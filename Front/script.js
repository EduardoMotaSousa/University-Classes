const usuario = "EduardoMotaSousa";
const repo = "University-Classes";

let historico = [];
let pastaAtual = "";

// CACHE EM MEMÓRIA
const cache = {};

//CARREGAR CONTEÚDO

async function carregarConteudo(pasta = "") {
  pastaAtual = pasta;

  const container = document.getElementById("pastas");
  container.innerHTML = "";

  const ignorar = [
    ".git", ".vscode", "node_modules","index.html","README.md", "output", "Front"
  ];

  let dados;

  try {
    // SE JÁ TEM NO CACHE

    if (cache[pasta]) {
      dados = cache[pasta];
    } else {
      const url = `https://api.github.com/repos/${usuario}/${repo}/contents/${pasta}`;
      
      const res = await fetch(url);
      dados = await res.json();

      // TRATAMENTO DE ERRO (RATE LIMIT)
      if (dados.message && dados.message.includes("rate limit")) {
        container.innerHTML =
          "<p>⚠️ Limite da API do GitHub atingido. Tente novamente mais tarde.</p>";
        return;
      }

      // SALVA NO CACHE
      cache[pasta] = dados;
    }

    // RENDERIZA
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

    // BOTÃO "+"
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

    // 🔹 CONTROLE BOTÃO HOME
    document.getElementById("homeBtn").style.display =
      historico.length ? "flex" : "none";

  } catch (erro) {
    container.innerHTML =
      "<p>❌ Erro ao carregar dados. Verifique sua conexão.</p>";
    console.error(erro);
  }
}

//NAVEGAÇÃO

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

//README (SEM CACHE POR ENQUANTO)

async function carregarReadme() {
  try {
    const url = `https://raw.githubusercontent.com/${usuario}/${repo}/main/README.md`;
    
    const res = await fetch(url);
    const markdown = await res.text();

    document.getElementById("readme-content").innerHTML =
      marked.parse(markdown);

  } catch (erro) {
    document.getElementById("readme-content").innerHTML =
      "<p>Erro ao carregar README.</p>";
  }
}

//INIT

carregarConteudo();
carregarReadme();