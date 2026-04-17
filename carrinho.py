import hub
import motor
import runloop
import distance_sensor

# Motores
porta_a = hub.port.A
porta_b = hub.port.B
porta_c = hub.port.C
porta_d = hub.port.D

sensor_porta = hub.port.E

async def main():
    while True:

        distancia = distance_sensor.distance(sensor_porta)

        if distancia is None:
            distancia = 1000

        # CAMINHO LIVRE
        if distancia > 100:
            motor.run(porta_a, -500)
            motor.run(porta_b, 500)
            motor.run(porta_c, -500)
            motor.run(porta_d, 500)

        # OBSTÁCULO
        else:
            motor.run(porta_a, -500)
            motor.run(porta_c, -500)
            motor.stop(porta_b)
            motor.stop(porta_d)

        await runloop.sleep_ms(50)

runloop.run(main())