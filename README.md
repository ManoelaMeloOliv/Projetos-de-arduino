# 🎵 Projeto Arduino Audio-LED Visualizer 💡✨

> *Transforme música em luzes vibrantes e uma experiência visual única!* 🎶🔊

---

## 📌 Sobre o Projeto

Este projeto integra hardware e software para criar um sistema interativo onde LEDs controlados por um Arduino reagem à frequência do áudio captado em tempo real.  

Usando um script Python que analisa o áudio via FFT, enviamos comandos para o Arduino acender LEDs conforme a intensidade e frequência detectadas — um verdadeiro espetáculo visual sincronizado com o som!  

Além disso, uma interface gráfica elegante exibe emojis e animações coloridas que representam o estado do áudio, tornando tudo ainda mais dinâmico e divertido. 😄🌈

---

## 🔧 Como Funciona

1. **Captura do áudio:** Microfone do computador capta sons ambiente.
2. **Análise em Python:** Identificação dos picos de frequência usando transformada rápida de Fourier (FFT).
3. **Comunicação serial:** Frequência convertida em comando enviado ao Arduino.
4. **Controle dos LEDs:** Arduino acende LEDs proporcionalmente à intensidade do som.
5. **Interface visual:** Python mostra emojis 😍😢 e uma barra colorida que muda com o volume, numa animação suave e envolvente.

---

## 🎥 Demonstração Visual 

[![Assista ao vídeo](https://img.youtube.com/vi/RKSI5nP27u8/maxresdefault.jpg)](https://www.youtube.com/watch?v=RKSI5nP27u8)


---

## 🚀 Instruções para Rodar

1. Conecte o Arduino ao computador via USB.

2. Faça upload do firmware Arduino (arquivo `.ino`).

3. Configure no Python a porta serial correta (`COM3`, `/dev/ttyACM0`, etc.).

4. Instale as dependências Python:

```bash
pip install pyaudio numpy pyserial emoji
````


---

Execute o script Python para iniciar a detecção e visualização.

## 🎨 Interface Gráfica & Animações

- Barra de progresso com gradiente arco-íris que cresce e diminui conforme o volume.

- Emojis que mudam expressando o humor do som:

  - 🎉 para sons altos e animados

  - 😴 para sons baixos ou silêncio

- Animações suaves criadas com Tkinter, trazendo vida e interação ao projeto.

## 🌟 Benefícios & Aplicações

✨ Projeto educacional para entender integração hardware-software.  
✨ Base para sistemas de iluminação interativa em festas e eventos.  
✨ Inspiração para projetos artísticos que respondem ao som.  
✨ Desenvolvimento de habilidades em programação, eletrônica e design de interfaces.

---



 
Sinta-se livre para usar, modificar e compartilhar!

## 👩‍💻 Sobre a Autora

**Manoela Melo de Oliveira**  
💻 [GitHub](https://github.com/ManoelaMeloOliv) | 🔗 [LinkedIn](https://linkedin.com/in/ManoelaMeloOliv)
