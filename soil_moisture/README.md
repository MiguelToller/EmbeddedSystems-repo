# 🌱 Monitoramento de Umidade de Solo com Arduino

> Projeto desenvolvido para a disciplina de Sistemas Embarcados, focado na leitura analógica de sensores e controle de hardware atuador.

## 📋 Descrição do Projeto
Este projeto consiste em um sistema embarcado capaz de monitorar a umidade do solo em tempo real utilizando um sensor higrômetro. O sistema realiza a conversão de sinais analógicos para digitais (ADC) no Arduino e oferece um feedback visual imediato através de um conjunto de LEDs, classificando a umidade do solo em três níveis de saturação: Seco, Moderado e Bem Úmido.

## 🛠️ Hardware Utilizado
* Placa Arduino Uno (ou compatível)
* Sensor de Umidade de Solo (Hastes + Módulo comparador)
* 1x LED Vermelho (Indicador de Solo Seco)
* 1x LED Amarelo (Indicador de Solo Moderado)
* 1x LED Azul/Verde (Indicador de Solo Bem Úmido)
* 3x Resistores (para os LEDs)
* Protoboard e Jumpers

## ⚙️ Lógica e Calibração (Thresholds)
Durante os testes de calibração aferidos no Monitor Serial, a condutividade do sensor operou na faixa aproximada de `300` (muito úmido) a `1023` (completamente seco). A lógica condicional foi estabelecida nos seguintes limiares:

* **Seco (> 900):** Resistência alta. O LED Vermelho acende.
* **Moderado (751 a 900):** Resistência intermediária. O LED Amarelo acende.
* **Bem Úmido (≤ 750):** Baixa resistência (alta condutividade da água). O LED Azul/Verde acende.

## 🚀 Como Executar
1. Realize a montagem do hardware conforme a seguinte pinagem:
   - `Pino 2` -> LED Azul/Verde
   - `Pino 3` -> LED Amarelo
   - `Pino 4` -> LED Vermelho
   - `Pino A0` -> Pino de Sinal Analógico do Sensor
2. Conecte o Arduino ao computador via cabo USB.
3. Abra a Arduino IDE e carregue o código `monitor_umidade.ino`.
4. Abra o **Monitor Serial** (configurado em 9600 baud) para visualizar a leitura dos valores em tempo real.

## 👨‍💻 Autor
**Luiz Miguel Toller Marconatto** *Desenvolvedor principal e responsável pela estruturação e testes do código.*
