const usuario = "EduardoMotaSousa";
const repo = "University-Classes";

let historico = [];
let pastaAtual = "";

let codigoAtual = "";
let arquivoAtual = "";

let arvoreRepositorio = [];

/* EXTENSÕES */

const extensoesValidas = [
  ".cpp",
  ".c",
  ".h"
];

/* IGNORAR */

const ignorar = [
  ".git",
  ".vscode",
  "node_modules",
  "Front",
  ".github",
  "dados.json",
  "output",
  "README.md",
  "index.html"
];


/* FORMATAR */

function formatarNome(nome){
  return nome
  .replaceAll("_"," ")
  .replaceAll("-"," - ");
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


/* CARREGAR ÁRVORE */

async function carregarArvore(){
  const url = `https://api.github.com/repos/${usuario}/${repo}/git/trees/main?recursive=1`;
  const res = await fetch(url);
  const dados = await res.json();
  arvoreRepositorio = dados.tree;
}


/* LISTAR ITENS */

function listarItens(pasta=""){

  let itens = [];
  let adicionados = new Set();

  for(const item of arvoreRepositorio){

    const path = item.path;
    const partes = path.split("/");

    /* ignora */
    if(partes.some(p => ignorar.includes(p))){
      continue;
    }

    /* HOME */
    if(pasta === ""){

      const primeiro = partes[0];

      if(!adicionados.has(primeiro)){
        adicionados.add(primeiro);

        if(item.type === "tree" || partes.length > 1){
          itens.push({
            tipo: "dir",
            nome: primeiro,
            path: primeiro
          });
        } else {
          itens.push({
            tipo: "file",
            nome: primeiro,
            path: path
          });
        }
      }

    }

    /* SUBPASTA */
    else{

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
      if(extensoesValidas.some(ext => item.path.endsWith(ext))){
        total++;
      }
    }
  }
  return total;
}


/* CARREGAR CONTEÚDO */

async function carregarConteudo(pasta=""){

  pastaAtual = pasta;

  const container = document.getElementById("pastas");
  const caminho = document.getElementById("caminho");

  container.innerHTML = "Carregando...";

  try{

    const dados = listarItens(pasta);
    container.innerHTML = "";

    let totalGeral = 0;

    for(const item of dados){

      const div = document.createElement("div");
      div.className = "card";

      /* PASTAS */
      if(item.tipo === "dir"){

        const qtd = contarAtividades(item.path);
        totalGeral += qtd;

        div.innerHTML = `
          <div class="card-icon">📁</div>
          <div class="card-title">${formatarNome(item.nome)}</div>
          <small>${qtd} atividades</small>
        `;

        div.onclick = () => {
          historico.push(pasta);
          carregarConteudo(item.path);
        };

      }

      /* ARQUIVOS */
      else{

        if(extensoesValidas.some(ext => item.nome.endsWith(ext))){
          totalGeral++;
        }

        div.innerHTML = `
          <div class="card-icon">📄</div>
          <div class="card-title">${item.nome}</div>
        `;

        div.onclick = () => {
          abrirCodigo(item.path, item.nome);
        };
      }

      container.appendChild(div);
    }

    /* CARD + */
    const add = document.createElement("div");
    add.className = "card-add";
    add.innerHTML = "+";
    add.onclick = () => {
      window.open(
        `https://github.com/${usuario}/${repo}/tree/main/${pastaAtual}`,
        "_blank"
      );
    };
    container.appendChild(add);

    /* HOME BUTTON */
    document.getElementById("homeBtn").style.display =
      historico.length ? "flex" : "none";

    /* CAMINHO */
    caminho.textContent = pasta
      ? formatarNome(pasta)
      : `Home • ${totalGeral} atividades`;

  }
  catch(erro){
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

    // converte Markdown → HTML, depois limpa o HTML antes de inserir
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

  arquivoAtual = nome;
  document.getElementById("nomeArquivo").innerText = nome;

  const url = `https://raw.githubusercontent.com/${usuario}/${repo}/main/${path}`;
  const resposta = await fetch(url);
  codigoAtual = await resposta.text();

  const codigo = document.getElementById("codigo");

  delete codigo.dataset.highlighted;

  codigo.textContent = codigoAtual;
  hljs.highlightElement(codigo);

  document.getElementById("popup").style.display = "flex";
}


/* FECHAR */

function fecharPopup(){
  document.getElementById("popup").style.display = "none";
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

/* ✅ abre/fecha o terminal flutuante */
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

  const parts = cmd.split(" ");
  const command = parts[0].toLowerCase();
  const args = parts.slice(1).join(" ").trim();

  switch(command){
    case "help":     cmdHelp();          break;
    case "ls":       cmdLs();            break;
    case "cd":       cmdCd(args);        break;
    case "cat":      await cmdCat(args); break;
    case "pwd":      cmdPwd();           break;
    case "whoami":   cmdWhoami();        break;
    case "uname":    cmdUname();         break;
    case "echo":     cmdEcho(args);      break;
    case "date":     cmdDate();          break;
    case "history":  cmdHistory();       break;
    case "neofetch": cmdNeofetch();      break;
    case "clear":    cmdClear();         break;
    default:
      terminalPrint(
        `<span class="t-red">bash: ${escapeHtml(command)}: command not found — tente <span class="t-green">help</span></span>`
      );
  }
}

function cmdHelp(){
  terminalPrint(`
<span class="t-orange">Comandos disponíveis:</span>
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

  /* ✅ remove emojis, espaços extras e barra final */
  args = args.replace(/[^\w\d.\-\/]/g, "").replace(/\/$/, "").trim();

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
  const existe = arvoreRepositorio.some(
    i => i.path === target && i.type === "tree"
  );

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
  const existe = arvoreRepositorio.some(
    i => i.path === target && i.type === "blob"
  );

  if(!existe){
    terminalPrint(
      `<span class="t-red">cat: ${escapeHtml(args)}: No such file or directory</span>`
    );
    return;
  }

  terminalPrint(`<span class="t-gray">Carregando...</span>`);

  try {
    const url = `https://raw.githubusercontent.com/${usuario}/${repo}/main/${target}`;
    const res = await fetch(url);
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

function cmdWhoami(){
  terminalPrint(`<span class="t-green">eduardo</span>`);
}

function cmdUname(){
  terminalPrint(
    `<span class="t-white">Linux university 6.8.0-51-generic #52-Ubuntu SMP PREEMPT_DYNAMIC x86_64 GNU/Linux</span>`
  );
}

function cmdEcho(args){
  terminalPrint(`<span class="t-white">${escapeHtml(args)}</span>`);
}

function cmdDate(){
  terminalPrint(`<span class="t-white">${new Date().toString()}</span>`);
}

function cmdHistory(){
  if(!terminalHistory.length) return;
  let html = "";
  [...terminalHistory].reverse().forEach((cmd, i) => {
    html += `<span class="t-gray">${String(i+1).padStart(4," ")}  ${escapeHtml(cmd)}</span>\n`;
  });
  terminalPrint(`<pre>${html}</pre>`);
}

function cmdClear(){
  document.getElementById("terminal-output").innerHTML = "";
}

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
</div>
  `);
}


/* INICIALIZAR TERMINAL */

function initTerminal(){
  updateTerminalPrompt();

  terminalPrint(`<span class="t-orange">University-Classes Terminal</span> — Ubuntu 24.04 LTS`);
  terminalPrint(`Digite <span class="t-green">help</span> para ver os comandos disponíveis.`);
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


/* INIT */

async function iniciar(){
  await carregarArvore();
  carregarConteudo();
  carregarReadme();
  initTerminal();
}

iniciar();