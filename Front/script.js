const usuario = "EduardoMotaSousa";
const repo = "University-Classes";

let historico = [];
let pastaAtual = "";

async function carregarConteudo(pasta = "") {
  pastaAtual = pasta;

  const url = `https://api.github.com/repos/${usuario}/${repo}/contents/${pasta}`;
  
  const res = await fetch(url);
  const dados = await res.json();

  const container = document.getElementById("pastas");
  container.innerHTML = "";

  const ignorar = [
    ".git", ".vscode", "node_modules",
    "index.html", "style.css", "script.js",
    "README.md", "output", "icon.png", "Front"
  ];

  dados.forEach(item => {
    if (ignorar.includes(item.name)) return;

    const div = document.createElement("div");
    div.className = "card";

    if (item.type === "dir") {
      div.innerHTML = `📁<br>${item.name}`;
      div.onclick = () => {
        historico.push(pasta);
        carregarConteudo(item.path);
      };
    } else {
      div.innerHTML = `📄<br>${item.name}`;
      div.onclick = () => window.open(item.download_url, "_blank");
    }

    container.appendChild(div);
  });

  // 🔥 BOTÃO "+"
  const add = document.createElement("div");
  add.className = "card-add";
  add.innerHTML = "+";

  add.onclick = () => {
    window.open(`https://github.com/${usuario}/${repo}/tree/main/${pastaAtual}`, "_blank");
  };

  container.appendChild(add);

  document.getElementById("voltar").style.display =
    historico.length ? "inline-block" : "none";
}

function voltar() {
  const anterior = historico.pop();
  carregarConteudo(anterior || "");
}

function irGithub() {
  window.open("https://github.com/EduardoMotaSousa");
}

function irLinkedin() {
  window.open("https://www.linkedin.com/in/eduardomotaads/");
}

/* README */
async function carregarReadme() {
  const url = `https://raw.githubusercontent.com/${usuario}/${repo}/main/README.md`;
  
  const res = await fetch(url);
  const markdown = await res.text();

  document.getElementById("readme-content").innerHTML =
    marked.parse(markdown);
}

/* INIT */
carregarConteudo();
carregarReadme();