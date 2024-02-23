import serial, time#,keyboard
import subprocess
from pynput.keyboard import Key, Controller

keyboard = Controller()


p = subprocess.Popen("C:\Program Files (x86)\DJI Flight Simulator\DJI_FS.exe")


hw_sensor = serial.Serial(port='COM11', baudrate=115200, timeout=1, write_timeout=1)

# # k = pykeyboard.PyKeyboard()

if __name__ == '__main__':
    
    try:
        while True:
            poll = p.poll()
            if poll is not None:
                hw_sensor.close()
                break
            raw_string_b = hw_sensor.readline()
            raw_string_s = raw_string_b.decode('utf-8')
            print(raw_string_b)
            if raw_string_s == "u0\r\n":
                # keyboard.press_and_release('w')
                keyboard.press('w')
                
                time.sleep(0.15)
                print("Arriba")
                #keyboard.release('w')
            if raw_string_s == "nu0\r\n":
                keyboard.release('w')
                time.sleep(0.15)

            if  raw_string_s == "d0\r\n":
                # keyboard.press_and_release('s')
                keyboard.press('s')
                time.sleep(0.15)
                print("abajo")

            if  raw_string_s == "gu\r\n":
                # keyboard.press_and_release('s')
                keyboard.press('f')
                time.sleep(0.200) 
                keyboard.release('f')
                print("arriba")

            if  raw_string_s == "gd\r\n":
                # keyboard.press_and_release('s')
                keyboard.press('r')
                time.sleep(0.200)
                keyboard.release('r')
                print("abajo")

            if  raw_string_s == "nd0\r\n":
                keyboard.release('s')
                time.sleep(0.15)

            if  raw_string_s == "l0\r\n":
                # keyboard.press_and_release('a')
                keyboard.press('a')
                time.sleep(0.15)
                #keyboard.release('a')
                print("izquierda")
            if  raw_string_s == "nl0\r\n":
                keyboard.release('a')
                time.sleep(0.15)

            if  raw_string_s == "r0\r\n":
                # keyboard.press_and_release('d')
                keyboard.press('d')
                time.sleep(0.15)
                #keyboard.release('d')
                print("derecha")
            if  raw_string_s == "nr0\r\n":
                keyboard.release('d')
                time.sleep(0.15)

     # -------------------------------------------------------------       
            if raw_string_s == "u1\r\n":
                # keyboard.press_and_release('w')
                keyboard.press(Key.up)
                
                time.sleep(0.15)
                print("Arriba")
                #keyboard.release('w')
            if raw_string_s == "nu1\r\n":
                keyboard.release(Key.up)
                time.sleep(0.15)

            if  raw_string_s == "d1\r\n":
                # keyboard.press_and_release('s')
                keyboard.press(Key.down)
                time.sleep(0.15)
                print("abajo")
            if  raw_string_s == "nd1\r\n":
                keyboard.release(Key.down)
                time.sleep(0.15)

            if  raw_string_s == "l1\r\n":
                # keyboard.press_and_release('a')
                keyboard.press(Key.left)
                time.sleep(0.15)
                print("izquierda")
            if  raw_string_s == "nl1\r\n":
                keyboard.release(Key.left)
                time.sleep(0.15)

            if  raw_string_s == "r1\r\n":
                # keyboard.press_and_release('d')
                keyboard.press(Key.right)
                time.sleep(0.15)
                print("derecha")
            if  raw_string_s == "nr1\r\n":
                keyboard.release(Key.right)
                time.sleep(0.15)

            if  raw_string_s == "return\r\n":
                keyboard.press('o')
                time.sleep(0.500)
                keyboard.release('o')
           
            if  raw_string_s == "c1\r\n":
                keyboard.press(Key.enter)
                time.sleep(0.500)
                keyboard.release(Key.enter)
    except:
        print("Exception occurred, somthing wrong...")
        hw_sensor.close()