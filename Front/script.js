const usuario = "EduardoMotaSousa";
const repo = "University-Classes";

let historico = [];

async function carregarConteudo(pasta = "") {
  const url = `https://api.github.com/repos/${usuario}/${repo}/contents/${pasta}`;
  
  const res = await fetch(url);
  const dados = await res.json();

  const container = document.getElementById("pastas");
  container.innerHTML = "";

  const ignorar = [
    ".git", ".vscode", "node_modules",
    "index.html", "style.css", "script.js",
    "README.md", "output", "icon.png"
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

/* README */
async function carregarReadme() {
  const url = "https://raw.githubusercontent.com/EduardoMotaSousa/University-Classes/main/README.md";
  
  const res = await fetch(url);
  const markdown = await res.text();

  document.getElementById("readme-content").innerHTML =
    marked.parse(markdown);
}

/* INIT */
carregarConteudo();
carregarReadme();