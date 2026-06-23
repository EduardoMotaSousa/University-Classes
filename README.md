<div align="center">

# University C++ Classes

![Status](https://img.shields.io/badge/status-em%20desenvolvimento-blue?style=flat)
![Linguagem](https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white)
![HTML5](https://img.shields.io/badge/HTML5-E34F26?style=flat&logo=html5&logoColor=white)
![CSS3](https://img.shields.io/badge/CSS3-1572B6?style=flat&logo=css3&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)
![GitHub Actions](https://img.shields.io/badge/GitHub%20Actions-2088FF?style=flat&logo=githubactions&logoColor=white)

**Repositório de estudos em C++ com interface web interativa integrada ao GitHub.**

[🌐 Acessar o site](https://eduardomotasousa.github.io/University-Classes/) 

</div>

------------------------------------------------------------------------

# 🎯 Sobre o projeto

O **University C++ Classes** começou como um repositório para armazenar
exercícios da graduação em **Análise e Desenvolvimento de Sistemas
(ADS)**.

Com a evolução do projeto, ele se tornou uma pequena plataforma de
aprendizado, o próprio repositório é interpretado por uma aplicação web,
exibindo exercícios, estatísticas, histórico de desenvolvimento e
ferramentas interativas.

O objetivo principal é unir:

-   Prática de programação em C++;
-   Organização de estudos;
-   Desenvolvimento front-end;
-   Automação;
-   Integração com APIs;
-   Boas práticas de versionamento.

------------------------------------------------------------------------

# ✨ Funcionalidades

## 📁 Explorador automático de exercícios

A interface não depende de cadastro manual.

O fluxo é:

 1.  Novo arquivo `.cpp` é adicionado;
 2.  GitHub Actions identifica a alteração;
 3.  A estrutura do repositório é transformada em `dados.json`;
 4.  O site atualiza automaticamente.

Novos exercícios aparecem sem modificar o HTML.

------------------------------------------------------------------------

## 💻 Visualizador de código

Arquivos C/C++ possuem uma visualização integrada com:

-   Syntax highlight;
-   Contador de linhas;
-   Navegação entre arquivos;
-   Copiar código;
-   Download;
-   Atalhos de teclado;
-   Visualização organizada em modal.

------------------------------------------------------------------------

## ⭐ Sistema de destaque

Os exercícios podem receber classificações:

  Ícone   Tipo                  Funcionamento
  ------- --------------------- -------------------------------------------
  ⭐      Destaque automático   Arquivos maiores ou mais relevantes
  💎      Favorito              Definidos manualmente em `favoritos.json`
  🔮      Especial              Combinação de favorito + destaque

------------------------------------------------------------------------

## 📊 Histórico de evolução

O projeto acompanha a própria evolução através de:

-   Heatmap de commits;
-   Atividade ao longo do tempo;
-   Histórico gerado automaticamente.

Os dados vêm de `commits.json`.

------------------------------------------------------------------------

## 📈 Estatísticas do projeto

Painel com informações como:

-   Quantidade de arquivos;
-   Linhas de código;
-   Arquivos de maior tamanho;
-   Organização das pastas;
-   Evolução do repositório.

------------------------------------------------------------------------

## 🐧 Terminal Linux simulado

Uma interface de terminal foi criada em JavaScript para interagir com os
dados do projeto.

Comandos disponíveis:

  Comando      Função
  ------------ ------------------------------
  `ls`         Lista arquivos
  `cd`         Navega entre pastas
  `cat`        Exibe arquivos
  `grep`       Pesquisa conteúdo
  `pwd`        Mostra localização atual
  `whoami`     Usuário simulado
  `neofetch`   Exibe informações do projeto
  `history`    Histórico de comandos
  `clear`      Limpa terminal

O terminal é apenas uma simulação local e não executa comandos reais no
sistema.

------------------------------------------------------------------------

# 🏗️ Arquitetura

    University-Classes/

    ├── .github/
    │   └── workflows/
    │       └── github-api.yml
    │           └── Geração automática dos dados

    ├── Front/
    │   ├── script.js
    │   │   └── Lógica da aplicação
    │   ├── style.css
    │   │   └── Interface visual
    │   └── icons
    │
    ├── Exercicios/
    │   └── Exercícios C++
    │
    ├── dados.json
    │   └── Estrutura automática do repositório
    │
    ├── commits.json
    │   └── Histórico de commits
    │
    ├── favoritos.json
    │   └── Curadoria manual
    │
    └── index.html
        └── Aplicação principal

------------------------------------------------------------------------

# ⚙️ Fluxo automático

    Push no GitHub
            ↓
    GitHub Actions executa
            ↓
    Consulta API / histórico Git
            ↓
    Gera dados.json e commits.json
            ↓
    Atualiza o repositório
            ↓
    GitHub Pages publica a aplicação

------------------------------------------------------------------------

# 🔒 Segurança

Medidas aplicadas:

-   Tokens protegidos por GitHub Secrets;
-   Sanitização de conteúdo HTML;
-   Proteção contra injeção no terminal;
-   Processamento local dos comandos.

------------------------------------------------------------------------

# 🛠️ Tecnologias

  Tecnologia       Uso
  ---------------- ------------------------
  C++              Exercícios e estudos
  HTML5            Estrutura da aplicação
  CSS3             Interface
  JavaScript       Sistema interativo
  GitHub API       Dados do projeto
  GitHub Actions   Automação
  GitHub Pages     Hospedagem
  highlight.js     Código colorido
  marked.js        Markdown
  DOMPurify        Segurança

------------------------------------------------------------------------

# 📚 Organização dos estudos

Os exercícios acompanham a evolução do aprendizado:

-   `01-Logica` --- Fundamentos;
-   `02-Code` --- Primeiros programas;
-   `03-Loop` --- Estruturas de repetição;
-   `04-Vetor` --- Arrays;
-   `05-Matrizes` --- Estruturas bidimensionais;
-   `SAVA_Loop` --- Exercícios complementares;
-   `SAVA_Vetores_Matrizes` --- Manipulação de dados;
-   `Exercicios_Douglas` --- Listas acadêmicas.

------------------------------------------------------------------------

<div align="center">
Desenvolvido por Eduardo Mota
ADS --- Estácio · 2026
</div>
