const usuario = "EduardoMotaSousa";
const repo = "University-Classes";

let arquivosFavoritos = new Set();


let historico = [];
let pastaAtual = "";

let arquivosNavegacao = [];
let arquivoIndex = 0;

let codigoAtual = "";
let arquivoAtual = "";

let arvoreRepositorio = [];

/* EXTENSÕES */

const extensoesValidas = [".cpp", ".c", ".h"];

/* IGNORAR */

const ignorar = [
  ".git", ".vscode", "node_modules", "Front", ".github",
  "dados.json", "favoritos.json", "output", "README.md", "commits.json", ".gitignore", "index.html"
];

/* FORMATAR */

function formatarNome(nome){
  return nome.replaceAll("_"," ").replaceAll("-"," - ");
}

/* PEGAR PASTA PAI */

function pegarPasta(path){
  const partes = path.split("/");
  partes.pop();
  return partes.join("/");
}

/* ORDENAR */

function ordenarItens(lista){
  return lista.sort((a,b)=>{
    if(a.tipo==="dir" && b.tipo!=="dir") return -1;
    if(a.tipo!=="dir" && b.tipo==="dir") return 1;
    return a.nome.localeCompare(b.nome,"pt-BR",{numeric:true});
  });
}

/* CARREGAR FAVORITOS */

async function carregarFavoritos(){
  try {
    const res = await fetch("favoritos.json");
    if (!res.ok) return;
    const dados = await res.json();
    arquivosFavoritos = new Set(dados.favoritos || []);
  } catch {
    arquivosFavoritos = new Set();
  }
}

/* CARREGAR ÁRVORE */

async function carregarArvore(){
  try {
    const res = await fetch("dados.json");
    if (!res.ok) throw new Error(`HTTP ${res.status}`);
    const dados = await res.json();
    arvoreRepositorio = dados.tree;
  } catch (erro) {
    console.error("Erro ao carregar árvore:", erro);
    document.getElementById("pastas").innerHTML = "Erro ao carregar arquivos.";
  }
}

/* LISTAR ITENS */

function listarItens(pasta=""){
  let itens = [];
  let adicionados = new Set();

  for(const item of arvoreRepositorio){
    const path = item.path;
    const partes = path.split("/");

    if(partes.some(p => ignorar.includes(p))) continue;

    if(pasta === ""){
      const primeiro = partes[0];
      if(!adicionados.has(primeiro)){
        adicionados.add(primeiro);
        if(item.type === "tree" || partes.length > 1){
          itens.push({ tipo: "dir", nome: primeiro, path: primeiro });
        } else {
          itens.push({ tipo: "file", nome: primeiro, path: path });
        }
      }
    } else {
      if(pegarPasta(path) === pasta){
        const nome = partes[partes.length - 1];
        itens.push({
          tipo: item.type === "tree" ? "dir" : "file",
          nome: nome,
          path: path
        });
      }
    }
  }

  return ordenarItens(itens);
}

/* CONTAR EXERCÍCIOS */

function contarAtividades(pasta){
  let total = 0;
  for(const item of arvoreRepositorio){
    if(item.path.startsWith(pasta + "/")){
      if(extensoesValidas.some(ext => item.path.endsWith(ext))) total++;
    }
  }
  return total;
}

/* CALCULAR ARQUIVOS DOURADOS */

function calcularDourados(itens) {
  const arquivos = itens.filter(i =>
    i.tipo === "file" && extensoesValidas.some(ext => i.nome.endsWith(ext))
  );

  if (arquivos.length === 0) return new Set();

  const comSize = arquivos.map(i => {
    const node = arvoreRepositorio.find(n => n.path === i.path);
    return { path: i.path, size: node?.size || 0 };
  });

  comSize.sort((a, b) => b.size - a.size);
  const qtdDourados = Math.max(1, Math.ceil(comSize.length * 0.1));
  return new Set(comSize.slice(0, qtdDourados).map(i => i.path));
}

/* CARREGAR CONTEÚDO */

async function carregarConteudo(pasta=""){
  pastaAtual = pasta;

  const container = document.getElementById("pastas");
  const caminho   = document.getElementById("caminho");

  container.innerHTML = "Carregando...";

  try {
    const dados   = listarItens(pasta);
    const dourados = calcularDourados(dados);

    arquivosNavegacao = dados.filter(i =>
      i.tipo === "file" && extensoesValidas.some(ext => i.nome.endsWith(ext))
    );

    container.innerHTML = "";
    let totalGeral = 0;

    // contadores para o cabeçalho
    let totalDourados  = 0;
    let totalFavoritos = 0;
    let totalEspeciais = 0;

    for(const item of dados){
      const div = document.createElement("div");
      div.className = "card";

      if(item.tipo === "dir"){
        const qtd = contarAtividades(item.path);
        totalGeral += qtd;

        // conta badges dentro da pasta
        const filhos = arvoreRepositorio.filter(n =>
          n.path.startsWith(item.path + "/") &&
          extensoesValidas.some(ext => n.path.endsWith(ext))
        );
        const filhosItens = filhos.map(n => ({
          tipo: "file", nome: n.path.split("/").pop(), path: n.path
        }));
        const douradosPasta = calcularDourados(filhosItens);

        const ePasta = filhos.filter(n => arquivosFavoritos.has(n.path) && douradosPasta.has(n.path)).length;
        const fPasta = filhos.filter(n => arquivosFavoritos.has(n.path) && !douradosPasta.has(n.path)).length;
        const dPasta = filhos.filter(n => douradosPasta.has(n.path) && !arquivosFavoritos.has(n.path)).length;

        let badges = "";
        if (ePasta > 0) badges += `<span class="badge badge-especial">🔮 ${ePasta}</span>`;
        if (fPasta > 0) badges += `<span class="badge badge-favorito">💎 ${fPasta}</span>`;
        if (dPasta > 0) badges += `<span class="badge badge-dourado">⭐ ${dPasta}</span>`;

        div.innerHTML = `
          <div class="card-icon">📁</div>
          <div class="card-title">${formatarNome(item.nome)}</div>
          <small>${qtd} atividades</small>
          ${badges ? `<div class="card-badges">${badges}</div>` : ""}
        `;

        div.onclick = () => {
          historico.push(pasta);
          carregarConteudo(item.path);
        };

      } else {
        if(extensoesValidas.some(ext => item.nome.endsWith(ext))) totalGeral++;

        const eDourado  = dourados.has(item.path);
        const eFavorito = arquivosFavoritos.has(item.path);
        const eEspecial = eFavorito && eDourado;
        const node      = arvoreRepositorio.find(n => n.path === item.path);
        const linhasAprox = node?.size ? Math.round(node.size / 30) : null;

        if (eEspecial) { totalEspeciais++; }
        else if (eFavorito) { totalFavoritos++; }
        else if (eDourado)  { totalDourados++;  }

        let icone = "📄";
        if (eEspecial)      icone = "🔮";
        else if (eFavorito) icone = "💎";
        else if (eDourado)  icone = "⭐";

        div.innerHTML = `
          <div class="card-icon">${icone}</div>
          <div class="card-title">${item.nome}</div>
          ${linhasAprox ? `<small>~${linhasAprox} linhas</small>` : ""}
        `;

        if (eEspecial)      div.classList.add("card-especial");
        else if (eFavorito) div.classList.add("card-favorito");
        else if (eDourado)  div.classList.add("card-dourado");

        div.onclick = () => abrirCodigo(item.path, item.nome);
      }

      container.appendChild(div);
    }

    /* CARD + */
    const add = document.createElement("div");
    add.className = "card-add";
    add.innerHTML = "+";
    add.onclick = () => window.open(
      `https://github.com/${usuario}/${repo}/tree/main/${pastaAtual}`, "_blank"
    );
    container.appendChild(add);

    /* HOME BUTTON */
    document.getElementById("homeBtn").style.display =
      historico.length ? "flex" : "none";

    /* CAMINHO + CONTADOR */
    let contadores = "";
    if (!pasta) {
      // na home não mostra contadores de arquivo (mostra nas pastas)
    } else {
      if (totalEspeciais > 0) contadores += ` · 🔮 ${totalEspeciais}`;
      if (totalFavoritos > 0) contadores += ` · 💎 ${totalFavoritos}`;
      if (totalDourados  > 0) contadores += ` · ⭐ ${totalDourados}`;
    }

    const tituloPagina = pasta
      ? `${formatarNome(pasta)}${contadores}`
      : `Home · ${totalGeral} atividades`;

    caminho.textContent = tituloPagina;
    atualizarTitulo(pasta
      ? `${formatarNome(pasta)} — University Classes`
      : "University Classes");

  } catch(erro) {
    container.innerHTML = "Erro ao carregar";
    console.log(erro);
  }
}

/* VOLTAR */

function voltar(){
  const anterior = historico.pop();
  carregarConteudo(anterior || "");
}

/* README */

async function carregarReadme() {
  try {
    const url = `https://raw.githubusercontent.com/${usuario}/${repo}/main/README.md`;
    const res = await fetch(url);
    if (!res.ok) throw new Error(`HTTP ${res.status}`);
    const markdown = await res.text();
    const htmlBruto = marked.parse(markdown);
    const htmlLimpo = DOMPurify.sanitize(htmlBruto);
    document.getElementById("readme-content").innerHTML = htmlLimpo;
  } catch (erro) {
    document.getElementById("readme-content").textContent = "Erro ao carregar README.";
    console.error("Erro no README:", erro);
  }
}

/* POPUP CÓDIGO */

async function abrirCodigo(path, nome){
  arquivoIndex = arquivosNavegacao.findIndex(i => i.path === path);

  const url = `https://raw.githubusercontent.com/${usuario}/${repo}/main/${path}`;
  const resposta = await fetch(url);
  codigoAtual = await resposta.text();

  const linhas = codigoAtual.split("\n").length;
  document.getElementById("nomeArquivo").innerText = `${nome} • ${linhas} linhas`;
  arquivoAtual = nome;

  const codigo = document.getElementById("codigo");
  delete codigo.dataset.highlighted;
  codigo.textContent = codigoAtual;
  hljs.highlightElement(codigo);

  atualizarTitulo(`${nome} — University Classes`);
  document.getElementById("popup").style.display = "flex";
  atualizarBotoesNavegacao();
}

/* FECHAR */

function fecharPopup(){
  document.getElementById("popup").style.display = "none";
  atualizarTitulo(pastaAtual
    ? `${formatarNome(pastaAtual)} — University Classes`
    : "University Classes");
}

/* COPIAR */

function copiarCodigo(){
  navigator.clipboard.writeText(codigoAtual);
}

/* DOWNLOAD */

function baixarCodigo(){
  const blob = new Blob([codigoAtual], {type:"text/plain"});
  const link = document.createElement("a");
  link.href = URL.createObjectURL(blob);
  link.download = arquivoAtual;
  link.click();
}

/* LINKS */

function irGithub(){
  window.open("https://github.com/EduardoMotaSousa", "_blank");
}

function irLinkedin(){
  window.open("https://www.linkedin.com/in/eduardomotaads/", "_blank");
}

/* TERMINAL */

let terminalPath = "";
let terminalHistory = [];
let terminalHistoryIndex = -1;

function toggleTerminal(){
  document.getElementById("terminal-float").classList.toggle("open");
  setTimeout(() => document.getElementById("terminal-input").focus(), 50);
}

function escapeHtml(text){
  return String(text)
    .replace(/&/g,"&amp;")
    .replace(/</g,"&lt;")
    .replace(/>/g,"&gt;");
}

function terminalPrint(html){
  const output = document.getElementById("terminal-output");
  const div = document.createElement("div");
  div.innerHTML = html;
  output.appendChild(div);
  const body = document.getElementById("terminal-body");
  body.scrollTop = body.scrollHeight;
}

function updateTerminalPrompt(){
  const path = terminalPath ? `~/${terminalPath}` : "~";
  document.getElementById("terminal-prompt").innerHTML =
    `<span class="t-green t-bold">eduardo@university</span><span class="t-white">:</span><span class="t-blue">${path}</span><span class="t-white">$&nbsp;</span>`;
  document.querySelector(".terminal-title").textContent =
    `eduardo@university: ${path}`;
}

function printCommandLine(cmd){
  const path = terminalPath ? `~/${terminalPath}` : "~";
  terminalPrint(
    `<span class="t-green t-bold">eduardo@university</span><span class="t-white">:</span><span class="t-blue">${path}</span><span class="t-white">$ ${escapeHtml(cmd)}</span>`
  );
}

async function terminalExecute(cmd){
  cmd = cmd.trim();
  if(!cmd) return;

  terminalHistory.unshift(cmd);
  terminalHistoryIndex = -1;
  printCommandLine(cmd);

  const parts   = cmd.split(" ");
  const command = parts[0].toLowerCase();
  const args    = parts.slice(1).join(" ").trim();

  switch(command){
    case "grep":     await cmdGrep(args); break;
    case "help":     cmdHelp();           break;
    case "ls":       cmdLs();             break;
    case "cd":       cmdCd(args);         break;
    case "cat":      await cmdCat(args);  break;
    case "pwd":      cmdPwd();            break;
    case "whoami":   cmdWhoami();         break;
    case "uname":    cmdUname();          break;
    case "echo":     cmdEcho(args);       break;
    case "date":     cmdDate();           break;
    case "history":  cmdHistory();        break;
    case "neofetch": cmdNeofetch();       break;
    case "clear":    cmdClear();          break;
    default:
      terminalPrint(
        `<span class="t-red">bash: ${escapeHtml(command)}: command not found — tente <span class="t-green">help</span></span>`
      );
  }
}

function cmdHelp(){
  terminalPrint(`
<span class="t-orange">Comandos disponíveis:</span>
  <span class="t-green">grep &lt;texto&gt; [arquivo]</span>  Busca texto nos arquivos
  <span class="t-green">ls</span>               Lista arquivos e pastas
  <span class="t-green">cd &lt;pasta&gt;</span>        Entra na pasta (cd .. para voltar)
  <span class="t-green">cat &lt;arquivo&gt;</span>    Mostra conteúdo do arquivo
  <span class="t-green">pwd</span>              Caminho atual
  <span class="t-green">whoami</span>           Usuário atual
  <span class="t-green">uname -a</span>         Info do sistema
  <span class="t-green">neofetch</span>         Stats com arte ASCII
  <span class="t-green">echo &lt;texto&gt;</span>     Imprime texto
  <span class="t-green">date</span>             Data e hora atual
  <span class="t-green">history</span>          Histórico de comandos
  <span class="t-green">clear</span>            Limpa o terminal
  `);
}

function cmdLs(){
  const itens = listarItens(terminalPath);
  if(!itens.length){
    terminalPrint(`<span class="t-gray">total 0</span>`);
    return;
  }
  let html = `<div class="t-ls">`;
  for(const item of itens){
    if(item.tipo === "dir"){
      html += `<span class="t-blue t-bold">📁 ${escapeHtml(item.nome)}/</span>`;
    } else {
      html += `<span class="t-white">📄 ${escapeHtml(item.nome)}</span>`;
    }
  }
  html += `</div>`;
  terminalPrint(html);
}

function cmdCd(args){
  args = args.replace(/['";&|`$]/g, "").trim().replace(/\/$/, "");

  if(!args || args === "~"){
    terminalPath = "";
    updateTerminalPrompt();
    return;
  }

  if(args === ".."){
    if(terminalPath){
      const partes = terminalPath.split("/");
      partes.pop();
      terminalPath = partes.join("/");
    }
    updateTerminalPrompt();
    return;
  }

  const target = terminalPath ? `${terminalPath}/${args}` : args;
  const existe = arvoreRepositorio.some(i => i.path === target && i.type === "tree");

  if(existe){
    terminalPath = target;
    updateTerminalPrompt();
  } else {
    terminalPrint(
      `<span class="t-red">bash: cd: ${escapeHtml(args)}: No such file or directory</span>`
    );
  }
}

async function cmdCat(args){
  if(!args){
    terminalPrint(`<span class="t-red">cat: missing operand</span>`);
    return;
  }

  const target = terminalPath ? `${terminalPath}/${args}` : args;
  const existe = arvoreRepositorio.some(i => i.path === target && i.type === "blob");

  if(!existe){
    terminalPrint(`<span class="t-red">cat: ${escapeHtml(args)}: No such file or directory</span>`);
    return;
  }

  terminalPrint(`<span class="t-gray">Carregando...</span>`);

  try {
    const url = `https://raw.githubusercontent.com/${usuario}/${repo}/main/${target}`;
    const res  = await fetch(url);
    const text = await res.text();
    document.getElementById("terminal-output").lastChild.remove();
    terminalPrint(`<pre class="t-cat">${escapeHtml(text)}</pre>`);
  } catch {
    terminalPrint(`<span class="t-red">cat: erro ao ler arquivo</span>`);
  }
}

function cmdPwd(){
  const path = terminalPath
    ? `/home/eduardo/university-classes/${terminalPath}`
    : "/home/eduardo/university-classes";
  terminalPrint(`<span class="t-white">${path}</span>`);
}

function cmdWhoami(){ terminalPrint(`<span class="t-green">eduardo</span>`); }

function cmdUname(){
  terminalPrint(
    `<span class="t-white">Linux university 6.8.0-51-generic #52-Ubuntu SMP PREEMPT_DYNAMIC x86_64 GNU/Linux</span>`
  );
}

function cmdEcho(args){ terminalPrint(`<span class="t-white">${escapeHtml(args)}</span>`); }

function cmdDate(){ terminalPrint(`<span class="t-white">${new Date().toString()}</span>`); }

function cmdHistory(){
  if(!terminalHistory.length) return;
  let html = "";
  [...terminalHistory].reverse().forEach((cmd, i) => {
    html += `<span class="t-gray">${String(i+1).padStart(4," ")}  ${escapeHtml(cmd)}</span>\n`;
  });
  terminalPrint(`<pre>${html}</pre>`);
}

function cmdClear(){ document.getElementById("terminal-output").innerHTML = ""; }

function cmdNeofetch(){
  const total = arvoreRepositorio.filter(i =>
    extensoesValidas.some(ext => i.path.endsWith(ext))
  ).length;
  const pastas = arvoreRepositorio.filter(
    i => i.type === "tree" && !i.path.includes("/")
  ).length;

  terminalPrint(`
<div class="t-neofetch">
  <pre class="t-ascii">        <span class="t-orange">_</span>
    <span class="t-orange">---(_)</span>
<span class="t-orange">_/  ---  \\</span>
<span class="t-orange">(_) |   |</span>
<span class="t-orange">  \\  --- _/</span>
    <span class="t-orange">---(_)</span></pre>
  <div class="t-info">
    <span><span class="t-green t-bold">eduardo</span><span class="t-white">@</span><span class="t-green t-bold">university</span></span>
    <span class="t-gray">─────────────────────────</span>
    <span><span class="t-orange">OS:</span>       <span class="t-white">Ubuntu 24.04 LTS x86_64</span></span>
    <span><span class="t-orange">Shell:</span>    <span class="t-white">bash 5.2.21</span></span>
    <span><span class="t-orange">Linguagem:</span> <span class="t-white">C++ (g++ 13.2)</span></span>
    <span><span class="t-orange">Repo:</span>     <span class="t-white">University-Classes</span></span>
    <span><span class="t-orange">Pastas:</span>   <span class="t-white">${pastas} módulos</span></span>
    <span><span class="t-orange">Arquivos:</span> <span class="t-white">${total} exercícios</span></span>
    <span><span class="t-orange">GitHub:</span>   <span class="t-white">EduardoMotaSousa</span></span>
  </div>
</div>`);
}

/* INICIALIZAR TERMINAL */

function initTerminal(){
  updateTerminalPrompt();
  terminalPrint(`<div style="text-align:center"><span class="t-orange">University-Classes Terminal</span> — Ubuntu 24.04 LTS</div>`);
  terminalPrint(`<div style="text-align:center">Digite <span class="t-green">help</span> para ver os comandos disponíveis.</div>`);
  terminalPrint(``);

  const input = document.getElementById("terminal-input");

  input.addEventListener("keydown", async function(e){
    if(e.key === "Enter"){
      const cmd = this.value;
      this.value = "";
      await terminalExecute(cmd);
    }
    if(e.key === "ArrowUp"){
      e.preventDefault();
      if(terminalHistoryIndex < terminalHistory.length - 1){
        terminalHistoryIndex++;
        this.value = terminalHistory[terminalHistoryIndex];
      }
    }
    if(e.key === "ArrowDown"){
      e.preventDefault();
      if(terminalHistoryIndex > 0){
        terminalHistoryIndex--;
        this.value = terminalHistory[terminalHistoryIndex];
      } else {
        terminalHistoryIndex = -1;
        this.value = "";
      }
    }
  });

  document.getElementById("terminal-body").addEventListener("click", function(){
    input.focus();
  });
}

/* GREP */

async function cmdGrep(args) {
  if (!args) {
    terminalPrint(`<span class="t-red">grep: uso: grep &lt;texto&gt; [arquivo]</span>`);
    return;
  }

  const partes  = args.match(/^"([^"]+)"\s*(.*)|^(\S+)\s*(.*)$/);
  const termo   = (partes[1] || partes[3]).toLowerCase();
  const arquivo = (partes[2] || partes[4] || "").trim();

  let alvos = [];

  if (arquivo) {
    const target = terminalPath ? `${terminalPath}/${arquivo}` : arquivo;
    const existe = arvoreRepositorio.find(i => i.path === target && i.type === "blob");
    if (!existe) {
      terminalPrint(`<span class="t-red">grep: ${escapeHtml(arquivo)}: arquivo não encontrado</span>`);
      return;
    }
    alvos = [{ path: target, nome: arquivo }];
  } else {
    alvos = listarItens(terminalPath)
      .filter(i => i.tipo === "file" && extensoesValidas.some(ext => i.nome.endsWith(ext)))
      .map(i => ({ path: i.path, nome: i.nome }));

    if (!alvos.length) {
      terminalPrint(`<span class="t-gray">Nenhum arquivo encontrado na pasta atual.</span>`);
      return;
    }
  }

  terminalPrint(`<span class="t-gray">Buscando "${escapeHtml(termo)}"...</span>`);

  let totalResultados = 0;

  for (const alvo of alvos) {
    try {
      const url  = `https://raw.githubusercontent.com/${usuario}/${repo}/main/${alvo.path}`;
      const res  = await fetch(url);
      if (!res.ok) continue;
      const texto = await res.text();

      const linhas     = texto.split("\n");
      const encontradas = [];

      linhas.forEach((linha, idx) => {
        if (linha.toLowerCase().includes(termo)){
          encontradas.push({ num: idx + 1, linha });
        }
      });

      if (encontradas.length) {
        totalResultados += encontradas.length;
        let html = `<span class="t-orange t-bold">${escapeHtml(alvo.nome)}</span>\n`;
        for (const r of encontradas) {
          const linhaSafe = escapeHtml(r.linha);
          const destacada = linhaSafe.replace(
            new RegExp(escapeHtml(termo), "gi"),
            match => `<span class="t-yellow t-bold">${match}</span>`
          );
          html += `<span class="t-gray">${String(r.num).padStart(4, " ")}:</span>  ${destacada}\n`;
        }
        terminalPrint(`<pre class="t-cat">${html}</pre>`);
      }
    } catch {
      terminalPrint(`<span class="t-red">Erro ao ler ${escapeHtml(alvo.nome)}</span>`);
    }
  }

  document.getElementById("terminal-output").children[
    document.getElementById("terminal-output").children.length - (totalResultados > 0 ? totalResultados + 1 : 1)
  ]?.remove();

  if (totalResultados === 0) {
    terminalPrint(`<span class="t-gray">Nenhuma ocorrência encontrada.</span>`);
  } else {
    terminalPrint(`<span class="t-green">${totalResultados} ocorrência(s) encontrada(s).</span>`);
  }
}

/* ATUALIZAR TÍTULO */

function atualizarTitulo(titulo) {
  document.title = titulo + "\u200B";
  setTimeout(() => { document.title = titulo; }, 50);
}

/* FECHAR POPUP COM ESCAPE */

document.addEventListener("keydown", e => {
  const popupAberto = document.getElementById("popup").style.display === "flex";
  if(e.key === "Escape"     && popupAberto) fecharPopup();
  if(e.key === "ArrowLeft"  && popupAberto) navegarPopup(-1);
  if(e.key === "ArrowRight" && popupAberto) navegarPopup(1);
});

/* NAVEGAÇÃO NO POPUP */

function atualizarBotoesNavegacao(){
  document.getElementById("btnAnterior").disabled = arquivoIndex <= 0;
  document.getElementById("btnProximo").disabled  = arquivoIndex >= arquivosNavegacao.length - 1;
}

function navegarPopup(direcao){
  const novoIndex = arquivoIndex + direcao;
  if(novoIndex < 0 || novoIndex >= arquivosNavegacao.length) return;
  const arquivo = arquivosNavegacao[novoIndex];
  abrirCodigo(arquivo.path, arquivo.nome);
}

/* HEATMAP DE COMMITS
   Lê commits.json gerado pelo GitHub Actions — sem limitação de API pública. */

async function carregarHeatmap() {
  const container = document.getElementById("heatmap");
  const tooltip   = document.getElementById("heatmap-tooltip");

  try {
    // lê o commits.json gerado pelo Actions (sem rate limit)
    const res = await fetch("commits.json");
    if (!res.ok) throw new Error(`HTTP ${res.status}`);
    const dados = await res.json();

    // agrupa commits por dia (YYYY-MM-DD em UTC)
    const commitsPorDia = {};
    for (const commit of dados.commits) {
      const dia = commit.date.slice(0, 10);
      commitsPorDia[dia] = (commitsPorDia[dia] || 0) + 1;
    }

    // gera os últimos 90 dias em UTC puro
    const agoraMs = Date.now();
    const umDiaMs = 86400000;
    const hojeMs  = agoraMs - (agoraMs % umDiaMs);

    const dias = [];
    for (let i = 89; i >= 0; i--) {
      const d   = new Date(hojeMs - i * umDiaMs);
      const key = d.toISOString().slice(0, 10);
      dias.push({ key, data: d, qtd: commitsPorDia[key] || 0 });
    }

    const maxQtd = Math.max(...dias.map(d => d.qtd), 1);

    function nivel(qtd) {
      if (qtd === 0) return 0;
      if (qtd <= maxQtd * 0.25) return 1;
      if (qtd <= maxQtd * 0.50) return 2;
      if (qtd <= maxQtd * 0.75) return 3;
      return 4;
    }

    // agrupa em semanas (dom=0 … sab=6) usando UTC
    const semanas = [];
    let semana = [];

    const primeiroDiaUTC = dias[0].data.getUTCDay();
    for (let i = 0; i < primeiroDiaUTC; i++) semana.push(null);

    for (const dia of dias) {
      semana.push(dia);
      if (dia.data.getUTCDay() === 6) {
        semanas.push(semana);
        semana = [];
      }
    }
    if (semana.length > 0) {
      while (semana.length < 7) semana.push(null);
      semanas.push(semana);
    }

    const colCount = semanas.length;

    // renderiza
    container.innerHTML = "";

    // labels dos meses alinhadas com o grid via CSS grid
    const mesesDiv = document.createElement("div");
    mesesDiv.className = "heatmap-meses";
    mesesDiv.style.gridTemplateColumns = `repeat(${colCount}, 20px)`;

    let mesAtual = -1;
    for (const sem of semanas) {
      const span = document.createElement("span");
      const primeiroValido = sem.find(d => d !== null);
      if (primeiroValido) {
        const mes = primeiroValido.data.getUTCMonth();
        if (mes !== mesAtual) {
          span.textContent = primeiroValido.data.toLocaleDateString("pt-BR", {
            month: "long", timeZone: "UTC"
          });
          mesAtual = mes;
        }
      }
      mesesDiv.appendChild(span);
    }
    container.appendChild(mesesDiv);

    // grid de células
    const grid = document.createElement("div");
    grid.className = "heatmap-grid";
    grid.style.gridTemplateColumns = `repeat(${colCount}, 20px)`;

    for (const sem of semanas) {
      const col = document.createElement("div");
      col.className = "heatmap-col";

      for (const dia of sem) {
        const cell = document.createElement("div");
        cell.className = "heatmap-cell";

        if (dia === null) {
          cell.style.visibility = "hidden";
        } else {
          cell.dataset.level = nivel(dia.qtd);

          cell.addEventListener("mouseenter", e => {
            const dataFmt = dia.data.toLocaleDateString("pt-BR", {
              weekday: "short", day: "2-digit", month: "short", timeZone: "UTC"
            });
            tooltip.textContent = dia.qtd === 0
              ? `${dataFmt} — nenhum commit`
              : `${dataFmt} — ${dia.qtd} commit${dia.qtd > 1 ? "s" : ""}`;
            tooltip.style.display = "block";
          });

          cell.addEventListener("mousemove", e => {
            const larguraTooltip = tooltip.offsetWidth;
            const larguraTela = window.innerWidth;

            // se não couber à direita, mostra à esquerda do cursor
            if (e.pageX + 12 + larguraTooltip > larguraTela) {
              tooltip.style.left = (e.pageX - larguraTooltip - 12) + "px";
            } else {
              tooltip.style.left = (e.pageX + 12) + "px";
            }

            tooltip.style.top = (e.pageY - 28) + "px";
          });
        }

        col.appendChild(cell);
      }
      grid.appendChild(col);
    }

    container.appendChild(grid);

  } catch (erro) {
    console.error("Erro ao carregar heatmap:", erro);
    container.innerHTML = `<p style="color:#94a3b8">Erro ao carregar commits.</p>`;
  }
}

/* ESTATÍSTICAS */

function carregarStats() {
  // total de arquivos
  const arquivos = arvoreRepositorio.filter(i =>
    extensoesValidas.some(ext => i.path.endsWith(ext))
  );
  document.getElementById("stat-arquivos").textContent = arquivos.length;

  // total de linhas estimadas (size / 30)
  const totalLinhas = arquivos.reduce((acc, i) => acc + Math.round((i.size || 0) / 30), 0);
  document.getElementById("stat-linhas").textContent =
    totalLinhas.toLocaleString("pt-BR");

  // pasta mais ativa (mais arquivos)
  const contagem = {};
  for (const item of arquivos) {
    const pasta = item.path.split("/")[0];
    contagem[pasta] = (contagem[pasta] || 0) + 1;
  }
  const pastaMaisAtiva = Object.entries(contagem)
    .sort((a, b) => b[1] - a[1])[0];
  if (pastaMaisAtiva) {
    document.getElementById("stat-pasta").textContent =
      `${formatarNome(pastaMaisAtiva[0])} (${pastaMaisAtiva[1]})`;
  }

  // arquivo mais longo
  const maior = arquivos.reduce((max, i) =>
    (i.size || 0) > (max.size || 0) ? i : max, arquivos[0]
  );
  if (maior) {
    const nome = maior.path.split("/").pop();
    const linhas = Math.round((maior.size || 0) / 30);
    document.getElementById("stat-maior").textContent =
      `${nome} (~${linhas} linhas)`;
  }
}

/* INIT */

/* Procure a sua função iniciar() no final do arquivo e deixe assim: */

async function iniciar(){
  await carregarArvore();
  await carregarFavoritos();
  carregarConteudo();
  carregarReadme();
  carregarHeatmap();
  carregarStats();
  initTerminal();

  // 🛠️ ADICIONE ESTE BLOCO AQUI EMBAIXO:
  document.getElementById("homeBtn").addEventListener("click", () => {
    historico = [];        // Limpa o histórico de pastas para o botão sumir
    carregarConteudo("");  // Voltar para a raiz da estrutura de pastas
    
    // Faz a página subir para o topo de forma suave
    window.scrollTo({
      top: 0,
      behavior: "smooth"   // "smooth" faz o efeito de rolagem deslizar. Se preferir instantâneo, use "instant"
    });
  });
}

iniciar();