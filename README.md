# University-Classes — C++ 🎓

![Status](https://img.shields.io/badge/status-em%20desenvolvimento-blue)

Repositório com exercícios e atividades práticas desenvolvidas durante o curso de Análise e Desenvolvimento de Sistemas (ADS).

O projeto começou como uma coleção organizada de exercícios em C++, mas evoluiu para uma plataforma web interativa capaz de navegar automaticamente pelo repositório, visualizar códigos e facilitar o acesso aos conteúdos diretamente no navegador.

---

## 🌐 Interface Web

O projeto possui uma interface web dinâmica integrada ao GitHub, permitindo:

- Navegar automaticamente pelas pastas do repositório
- Abrir exercícios e códigos sem acessar o GitHub
- Visualizar códigos com destaque de sintaxe
- Copiar códigos para a área de transferência
- Baixar arquivos diretamente
- Utilizar um terminal Linux integrado
- Ler este README diretamente no site
- Atualização automática ao adicionar novas pastas ou exercícios

🔗 Acesse:

https://eduardomotasousa.github.io/University-Classes/

---

## 📸 Funcionalidades

### 📁 Navegação automática

As pastas são detectadas automaticamente através da API/árvore do GitHub.

Não é necessário alterar HTML ou JavaScript ao adicionar novos conteúdos.

Exemplo:

Nova pasta criada

↓

Push no GitHub

↓

Atualização automática do site

---

### 💻 Visualizador de Código

Cada exercício pode ser aberto em um popup interativo contendo:

- Destaque de sintaxe C/C++
- Contagem de linhas do arquivo
- Botão de copiar código
- Download do arquivo
- Visualização sem sair da página
- Fechar com a tecla Escape

---

### ⭐ Cards Dourados

Os arquivos mais trabalhados de cada pasta recebem destaque visual automático:

- O top 10% dos arquivos por tamanho recebe borda dourada e ícone ⭐
- Em pastas com poucos arquivos, pelo menos o maior sempre é destacado
- A estimativa de linhas é calculada a partir do tamanho em bytes, sem requisições extras
- O destaque é dinâmico — atualiza automaticamente conforme novos exercícios são adicionados

---

### 🔤 Título Dinâmico

O título da aba do navegador muda conforme a navegação:

- Na home → `University Classes`
- Dentro de uma pasta → `Nome da Pasta — University Classes`
- Com um arquivo aberto → `arquivo.cpp — University Classes`

---

### 🐧 Terminal Linux Integrado

O projeto também possui um terminal Linux para comandos e acesso de arquivos.

Objetivos:

- Aprender comandos Linux
- Praticar ambiente de desenvolvimento
- Simular fluxo real de programação

Comandos disponíveis:

| Comando | Descrição |
|---------|-----------|
| `ls` | Lista arquivos e pastas |
| `cd <pasta>` | Entra na pasta (cd .. para voltar) |
| `cat <arquivo>` | Mostra conteúdo do arquivo |
| `grep <texto> [arquivo]` | Busca texto nos arquivos .cpp da pasta atual ou em um arquivo específico |
| `pwd` | Caminho atual |
| `whoami` | Usuário atual |
| `uname -a` | Info do sistema |
| `neofetch` | Stats com arte ASCII |
| `echo <texto>` | Imprime texto |
| `date` | Data e hora atual |
| `history` | Histórico de comandos |
| `clear` | Limpa o terminal |

---

## 🛠️ Tecnologias

![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white)
![HTML5](https://img.shields.io/badge/HTML5-E34F26?style=flat&logo=html5&logoColor=white)
![CSS3](https://img.shields.io/badge/CSS3-1572B6?style=flat&logo=css3&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat&logo=javascript&logoColor=black)
![Git](https://img.shields.io/badge/Git-F05032?style=flat&logo=git&logoColor=white)
![GitHub API](https://img.shields.io/badge/GitHub%20API-181717?style=flat&logo=github&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=flat&logo=linux&logoColor=black)

---

## 🧠 Objetivos do Projeto

- Organizar estudos de forma visual
- Praticar lógica de programação
- Aprender C++
- Estudar Git e GitHub
- Consumir APIs
- Aprender HTML, CSS e JavaScript
- Explorar Linux
- Criar projetos reais durante o aprendizado

---

## ⚙️ Funcionamento

O site utiliza um arquivo `dados.json` gerado automaticamente pelo GitHub Actions a cada push, contendo a árvore completa do repositório. Isso elimina chamadas diretas à API durante a navegação, evitando rate limits e acelerando o carregamento.

### Recursos implementados:

✔ Carregamento automático de pastas

✔ Cache via `dados.json` local

✔ Navegação dinâmica

✔ Contagem automática de atividades

✔ Ignorar arquivos internos automaticamente

✔ Visualizador de código integrado com contagem de linhas

✔ Download de arquivos

✔ Terminal Linux com suporte a `grep`

✔ Cards dourados para arquivos mais trabalhados

✔ Título da aba dinâmico

✔ Sanitização de conteúdo com DOMPurify

---

## 🔒 Segurança

- O token de acesso à API do GitHub fica exclusivamente no GitHub Actions (secrets), nunca exposto no front-end
- O conteúdo do README é sanitizado com **DOMPurify** antes de ser renderizado, prevenindo ataques XSS
- O terminal simulado não executa código real no servidor — todos os comandos são processados localmente em JavaScript

---

## 📁 Estrutura do Projeto

### Conteúdo exibido no site

Estas pastas aparecem automaticamente:

| Pasta | Conteúdo |
|---------|----------|
| 01-Lógica | Exercícios de lógica |
| 02-Code | Exercícios introdutórios |
| 03-Loop | Estruturas de repetição |
| 04-Vetor | Vetores |
| 05-Matrizes | Matrizes |
| SAVA Loop | Exercícios complementares |
| SAVA Vetores & Matrizes | Vetores e matrizes |
| Exercícios Douglas | Lista de exercícios |

---

### Estrutura interna

Arquivos utilizados pelo funcionamento do projeto:

| Pasta/Arquivo | Função |
|--------------|---------| 
| Front | CSS, JavaScript e recursos visuais |
| .github | Automação GitHub Actions |
| dados.json | Cache da árvore do repositório |
| index.html | Página principal |
| README.md | Documentação |

Esses arquivos são ocultados automaticamente da interface.

---

## 🤖 Uso de Inteligência Artificial

Parte da interface web foi desenvolvida com auxílio de IA.

O objetivo foi:

- Aprender conceitos de front-end
- Entender integração com APIs
- Ajustar e evoluir código manualmente
- Utilizar IA como ferramenta de apoio ao estudo

---

Desenvolvido durante meus estudos em ADS utilizando C++, GitHub, HTML, CSS, JavaScript e Linux.