# 🎲 Corrida dos Dados: Até 100!

Um jogo de dados divertido e viciante feito em linguagem C!  
Desafie a máquina em uma corrida até 100 pontos — use sua sorte, calcule seus riscos e jogue com estratégia.

---

## 📜 Regras do Jogo

- Cada jogador começa com **0 pontos**.
- A cada turno, você pode **rolar o dado quantas vezes quiser**.
- Cada valor obtido **é somado** à pontuação da rodada.
- **MAS CUIDADO!** Se você tirar **1**, perde tudo da rodada e passa a vez.
- Você pode **encerrar a rodada a qualquer momento**, somando os pontos ao seu total.
- A máquina joga automaticamente, parando ao atingir **20 pontos** na rodada (se não cair em um 1).
- O primeiro a chegar em **100 pontos ganha**!

---

## 🧠 Estratégia

🟢 Quanto mais você arriscar, maior sua chance de pontuar alto...  
🔴 ...mas um simples 1 pode acabar com tudo.  
⚙️ A máquina tem sua própria lógica: ela para ao atingir 20 pontos em uma rodada — será que isso é esperto?

---

## 🖥️ Como executar

Certifique-se de ter o **compilador GCC** instalado.

```bash
gcc corrida_dos_dados.c -o corrida-dos-dados
./corrida-dos-dados