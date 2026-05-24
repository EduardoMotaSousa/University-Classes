const usuario = "EduardoMotaSousa";
const repo = "University-Classes";

let historico = [];
let pastaAtual = "";

/* CACHE */
const cache = {};
const cacheCount = {};

/* EXTENSÕES VÁLIDAS */
const extensoesValidas = [".cpp", ".c", ".h"];

/* ITENS IGNORADOS */
const ignorar = [
  ".git",
  ".vscode",
  "node_modules",
  "index.html",
  "README.md",
  "Front",
  "output"
];

/* FORMATAR NOME */
function formatarNome(nome) {

  return nome
    .replaceAll("_", " ")
    .replaceAll("-", " - ");
}

/* CONTAR ATIVIDADES */
async function contarAtividades(pasta) {

  if (cacheCount[pasta] !== undefined) {
    return cacheCount[pasta];
  }

  const url =
    `https://api.github.com/repos/${usuario}/${repo}/contents/${pasta}`;

  const res = await fetch(url);
  const dados = await res.json();

  let total = 0;

  for (const item of dados) {

    if (item.type === "file") {

      if (
        extensoesValidas.some(ext =>
          item.name.endsWith(ext)
        )
      ) {
        total++;
      }
    }
  }

  cacheCount[pasta] = total;

  return total;
}

/* ORDENAR */
function ordenarItens(lista) {

  return lista.sort((a, b) => {

    /* PASTAS PRIMEIRO */
    if (a.type === "dir" && b.type !== "dir") return -1;
    if (a.type !== "dir" && b.type === "dir") return 1;

    /* PEGA NÚMEROS */
    const numA =
      parseInt(a.name.match(/\d+/));

    const numB =
      parseInt(b.name.match(/\d+/));

    /* ORDENA NUMERICAMENTE */
    if (!isNaN(numA) && !isNaN(numB)) {
      return numA - numB;
    }

    /* FALLBACK */
    return a.name.localeCompare(
      b.name,
      "pt-BR",
      { numeric: true }
    );
  });
}

/* CARREGAR CONTEÚDO */
async function carregarConteudo(pasta = "") {

  pastaAtual = pasta;

  const container =
    document.getElementById("pastas");

  const caminho =
    document.getElementById("caminho");

  container.innerHTML = "Carregando...";

  let dados;

  try {

    /* CACHE */
    if (cache[pasta]) {

      dados = cache[pasta];

    } else {

      const url =
        `https://api.github.com/repos/${usuario}/${repo}/contents/${pasta}`;

      const res = await fetch(url);

      if (!res.ok) {
        throw new Error("Erro API");
      }

      dados = await res.json();

      cache[pasta] = dados;
    }

    container.innerHTML = "";

    /* ORDENA */
    dados = ordenarItens(dados);

    let totalGeral = 0;

    for (const item of dados) {

      if (ignorar.includes(item.name)) {
        continue;
      }

      const div =
        document.createElement("div");

      div.className = "card";

      /* PASTAS */
      if (item.type === "dir") {

        const qtd =
          await contarAtividades(item.path);

        totalGeral += qtd;

        div.innerHTML = `
          <div class="card-icon">
            📁
          </div>

          <div class="card-title">
            ${formatarNome(item.name)}
          </div>

          <small>
            ${qtd} atividades
          </small>
        `;

        div.onclick = () => {

          historico.push(pasta);

          carregarConteudo(item.path);
        };

      } else {

        /* ARQUIVOS */

        if (
          extensoesValidas.some(ext =>
            item.name.endsWith(ext)
          )
        ) {
          totalGeral++;
        }

        div.innerHTML = `
          <div class="card-icon">
            📄
          </div>

          <div class="card-title">
            ${item.name}
          </div>
        `;

        div.onclick = () => {
          window.open(
            item.download_url,
            "_blank"
          );
        };
      }

      container.appendChild(div);
    }

    /* CARD + */
    const add =
      document.createElement("div");

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
      historico.length
        ? "flex"
        : "none";

    /* CAMINHO */
    caminho.textContent =
      pasta
        ? formatarNome(pasta)
        : `Home • ${totalGeral} atividades`;

  } catch (erro) {

    container.innerHTML =
      "<p>❌ Erro ao carregar dados.</p>";

    console.error(erro);
  }
}

/* VOLTAR */
function voltar() {

  const anterior = historico.pop();

  carregarConteudo(anterior || "");
}

/* LINKS */
function irGithub() {

  window.open(
    "https://github.com/EduardoMotaSousa"
  );
}

function irLinkedin() {

  window.open(
    "https://www.linkedin.com/in/eduardomotaads/"
  );
}

/* README */
async function carregarReadme() {

  try {

    const url =
      `https://raw.githubusercontent.com/${usuario}/${repo}/main/README.md`;

    const res = await fetch(url);

    const markdown =
      await res.text();

    document.getElementById(
      "readme-content"
    ).innerHTML =
      marked.parse(markdown);

  } catch {

    document.getElementById(
      "readme-content"
    ).innerHTML =
      "Erro ao carregar README";
  }
}

/* INIT */
carregarConteudo();
carregarReadme();