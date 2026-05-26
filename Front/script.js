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

  // ✅ partes definido ANTES do ignorar
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

        /* ✅ CORREÇÃO: usa item.type === "tree" além de partes.length > 1 */
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

async function carregarReadme(){
  try{
    const url = `https://raw.githubusercontent.com/${usuario}/${repo}/main/README.md`;
    const res = await fetch(url);
    const markdown = await res.text();
    document.getElementById("readme-content").innerHTML = marked.parse(markdown);
  }
  catch{
    document.getElementById("readme-content").innerHTML = "Erro ao carregar README";
  }
}


/* POPUP */

async function abrirCodigo(path, nome){

  arquivoAtual = nome;
  document.getElementById("nomeArquivo").innerText = nome;

  const url = `https://raw.githubusercontent.com/${usuario}/${repo}/main/${path}`;
  const resposta = await fetch(url);
  codigoAtual = await resposta.text();

  const codigo = document.getElementById("codigo");

  // ✅ Remove a marca do highlight anterior
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


/* INIT */

async function iniciar(){
  await carregarArvore();
  carregarConteudo();
  carregarReadme();
}

iniciar();