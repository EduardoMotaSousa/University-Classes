const usuario = "EduardoMotaSousa";
const repo = "University-Classes";

let historico = [];
let pastaAtual = "";

// CACHE
const cache = {};

async function carregarConteudo(pasta = "") {
  pastaAtual = pasta;

  const container = document.getElementById("pastas");
  const caminho = document.getElementById("caminho");

  container.innerHTML = "Carregando...";

  const ignorar = [
    ".git", ".vscode", "node_modules",
    "index.html", "README.md",
    "Front", "output"
  ];

  let dados;

  try {

    if (cache[pasta]) {
      dados = cache[pasta];
    } else {
      const url = `https://api.github.com/repos/${usuario}/${repo}/contents/${pasta}`;
      const res = await fetch(url);

      if (!res.ok) throw new Error("Erro API");

      dados = await res.json();
      cache[pasta] = dados;
    }

    container.innerHTML = "";

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

    // BOTÃO +
    const add = document.createElement("div");
    add.className = "card-add";
    add.innerHTML = "+";

    add.onclick = () => {
      window.open(`https://github.com/${usuario}/${repo}/tree/main/${pastaAtual}`, "_blank");
    };

    container.appendChild(add);

    // BOTÃO HOME
    document.getElementById("homeBtn").style.display =
      historico.length ? "flex" : "none";

    // CAMINHO
    caminho.textContent = pasta || "";

  } catch (erro) {
    container.innerHTML = "<p>❌ Erro ao carregar dados.</p>";
    console.error(erro);
  }
}

// VOLTAR
function voltar() {
  const anterior = historico.pop();
  carregarConteudo(anterior || "");
}

// LINKS
function irGithub() {
  window.open("https://github.com/EduardoMotaSousa");
}

function irLinkedin() {
  window.open("https://www.linkedin.com/in/eduardomotaads/");
}

// README
async function carregarReadme() {
  try {
    const url = `https://raw.githubusercontent.com/${usuario}/${repo}/main/README.md`;
    const res = await fetch(url);
    const markdown = await res.text();

    document.getElementById("readme-content").innerHTML =
      marked.parse(markdown);

  } catch {
    document.getElementById("readme-content").innerHTML =
      "Erro ao carregar README";
  }
}

// INIT
carregarConteudo();
carregarReadme();