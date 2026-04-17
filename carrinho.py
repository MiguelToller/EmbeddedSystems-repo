import hub
import motor
import runloop
import distance_sensor

# --- CONFIGURAÇÃO DE PORTAS ---
# Motores das rodas (Certifique-se que os cabos estão nestas portas)
porta_a = hub.port.A
porta_b = hub.port.B
porta_c = hub.port.C
porta_d = hub.port.D

# Sensor de Distância (Os "olhinhos" do robô)
sensor_porta = hub.port.E

async def main():
    print("Iniciando Robô Autônomo...")
    
    while True:
        # 1. Lê a distância do sensor
        distancia = distance_sensor.distance(sensor_porta)

        # 2. Tratamento de erro: Se o sensor não detectar nada, 
        # ele retorna 'None'. Vamos considerar como 1000mm (caminho livre).
        if distancia is None:
            distancia = 1000

        # --- LÓGICA DE DECISÃO ---

        # SE detectar algo a menos de 100mm (10 centímetros)
        if distancia < 100:
            print("Obstáculo detectado! Desviando...")
            # MANOBRA DE DESVIO: Gira para o lado
            # Paramos os motores de um lado e giramos os do outro
            motor.run(porta_a, -500)
            motor.run(porta_c, -500)
            motor.stop(porta_b)
            motor.stop(porta_d)

        # CASO CONTRÁRIO (Distância maior que 100mm = Caminho livre)
        else:
            # MOVER PARA FRENTE
            # Ajustamos as velocidades para o robô ir reto
            motor.run(porta_a, -500)
            motor.run(porta_b, 500)
            motor.run(porta_c, -500)
            motor.run(porta_d, 500)

        # Pequena pausa para o processador respirar
        await runloop.sleep_ms(50)

# Executa o programa
runloop.run(main())
