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

---

## 🎯 Sobre o Projeto

Este repositório nasceu como um simples organizador de exercícios de C++ do curso de **Análise e Desenvolvimento de Sistemas (ADS)**. Com o tempo, evoluiu para algo muito além do esperado. Uma **plataforma web** que lê o próprio repositório, exibe os exercícios com destaque de sintaxe, rastreia minha evolução por commits e oferece até um terminal Linux simulado.

O projeto une lógica de programação estudada em sala com desenvolvimento web, automação via GitHub Actions e consumo de APIs.

---

## 🌐 Interface Web

Acesse em: **[eduardomotasousa.github.io/University-Classes](https://eduardomotasousa.github.io/University-Classes/)**

A interface detecta automaticamente os arquivos do repositório e os exibe sem necessidade de atualizar o HTML manualmente. Basta criar um novo exercício, fazer push, e ele aparece no site.

---

## ✨ Funcionalidades

### 📁 Navegação automática por repositório
Os arquivos e pastas são carregados dinamicamente a partir de um `dados.json` gerado pelo **GitHub Actions** a cada push. Zero configuração manual para adicionar novos exercícios.

### 💻 Visualizador de código
Cada arquivo `.cpp` ou `.c` pode ser aberto num popup com:
- Destaque de sintaxe via **highlight.js**
- Contagem de linhas do arquivo
- Navegação entre arquivos com as setas ← → do teclado ou botões na tela
- Botão de copiar e download
- Fechar com **Escape**

### 🏅 Sistema de destaque por relevância
Os arquivos recebem categorias visuais automáticas e manuais:

| Ícone | Categoria | Critério |
|-------|-----------|----------|
| ⭐ | **Dourado** | Top 10% maiores arquivos da pasta (automático) |
| 💎 | **Favorito** | Curadoria manual via `favoritos.json` |
| 🔮 | **Especial** | Arquivo que é favorito E dourado ao mesmo tempo |

### 📊 Heatmap de commits
Gráfico de calor dos últimos 90 dias de atividade no repositório, com tooltip interativo ao passar o mouse em cada dia. Os dados são gerados pelo GitHub Actions com autenticação, sem limitações da API pública.

### 📈 Estatísticas do repositório
Painel com métricas calculadas automaticamente:
- Total de arquivos de código
- Total de linhas estimadas
- Pasta mais ativa
- Arquivo mais longo

### 🐧 Terminal Linux simulado
Terminal interativo com estética Ubuntu acessível por um botão flutuante. Suporta comandos reais integrados ao repositório:

| Comando | Descrição |
|---------|-----------|
| `ls` | Lista arquivos e pastas |
| `cd <pasta>` | Navega entre pastas |
| `cat <arquivo>` | Exibe conteúdo de um arquivo |
| `grep <texto> [arquivo]` | Busca texto nos arquivos `.cpp` |
| `pwd` | Exibe caminho atual |
| `whoami` | Exibe usuário |
| `uname -a` | Informações do sistema simulado |
| `neofetch` | Estatísticas do projeto em arte ASCII |
| `echo`, `date`, `history`, `clear` | Comandos utilitários |

### 🔤 Título dinâmico da aba
O título do navegador muda conforme a navegação: pasta atual, arquivo aberto ou página inicial.

---

## ⚙️ Arquitetura técnica

```
University-Classes/
├── .github/
│   └── workflows/
│       └── github-api.yml   # Automação: gera dados.json e commits.json a cada push
├── Front/
│   ├── script.js            # Toda a lógica da interface
│   ├── style.css            # Estilos
│   └── icon.png             # Ícone do site
├── dados.json               # Árvore do repositório (gerado pelo Actions)
├── commits.json             # Histórico de commits para o heatmap (gerado pelo Actions)
├── favoritos.json           # Curadoria manual de arquivos favoritos
├── index.html               # Página principal
├── 01-Logica/               # Exercícios de lógica
├── 02-Code/                 # Exercícios introdutórios
├── 03-Loop/                 # Estruturas de repetição
├── 04-Vetor/                # Vetores
├── 05-Matrizes/             # Matrizes
├── SAVA_Loop/               # Exercícios complementares de loop
├── SAVA_Vetores_&_Matrizes/ # Exercícios complementares
└── Exercicios_Douglas/      # Lista de exercícios do professor
```

### Fluxo de atualização automática

``` 
Push no GitHub
     ↓
GitHub Actions executa com histórico completo (fetch-depth: 0)
     ↓
Gera dados.json  ←  Árvore completa via API autenticada
Gera commits.json ←  git log --all (últimos 365 dias, todas as branches, sem limite)
     ↓
Commit automático com [skip ci] para evitar loops
     ↓
Site lê os arquivos locais — sem chamadas diretas à API
```

Essa arquitetura elimina o rate limit da API pública (60 req/hora) e garante que o site funcione mesmo offline, usando os dados em cache.

---

## 🔒 Segurança

| Medida | Implementação |
|--------|---------------|
| Token de API protegido | Fica exclusivamente nos **GitHub Secrets**, nunca exposto no front-end |
| Proteção contra XSS | Conteúdo do README sanitizado com **DOMPurify** antes de ser inserido no DOM |
| Terminal sem execução real | Todos os comandos são processados em JavaScript local — nada é executado no servidor |
| Inputs do terminal sanitizados | Função `escapeHtml()` aplicada em todos os inputs antes de renderizar |

---

## 🛠️ Tecnologias utilizadas

| Tecnologia | Uso |
|------------|-----|
| **C++** | Linguagem principal dos exercícios |
| **HTML5 / CSS3** | Estrutura e estilo da interface |
| **JavaScript (ES2022+)** | Toda a lógica da interface (fetch, DOM, async/await) |
| **GitHub API** | Fonte dos dados do repositório e commits |
| **GitHub Actions** | Automação da geração dos JSONs a cada push |
| **GitHub Pages** | Hospedagem gratuita do site |
| **highlight.js** | Destaque de sintaxe C++ no visualizador |
| **marked.js** | Renderização do README em Markdown |
| **DOMPurify** | Sanitização de HTML para segurança |

---

## 🤖 Uso de Inteligência Artificial

Parte significativa da interface web foi desenvolvida com auxílio de IA.

O processo foi sempre colaborativo: eu definia o que queria, entendia o código gerado, testava, depurava e solicitava ajustes. A IA foi uma ferramenta de aprendizado, não um substituto para o entendimento.

---

## 📚 Conteúdo do repositório

Os exercícios estão organizados por módulo, acompanhando a progressão do curso:

| Pasta | Conteúdo |
|-------|----------|
| `01-Logica` | Lógica de programação básica |
| `02-Code` | Primeiros programas em C++ |
| `03-Loop` | Estruturas de repetição (`for`, `while`, `do while`) |
| `04-Vetor` | Arrays e vetores |
| `05-Matrizes` | Matrizes bidimensionais |
| `SAVA_Loop` | Exercícios complementares de repetição |
| `SAVA_Vetores_&_Matrizes` | Exercícios complementares de estruturas |
| `Exercicios_Douglas` | Lista de exercícios do professor Douglas |

---

<div align="center">

Desenvolvido por **Eduardo Mota** · ADS — Estácio · 2026

</div>