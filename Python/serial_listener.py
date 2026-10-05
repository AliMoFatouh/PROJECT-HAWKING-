import serial


class SerialListener:
    def __init__(self):
        self.port = "/dev/ttyACM0"
        self.baudrate = 115200
        self.serial = serial.Serial(
            self.port,
            self.baudrate,
            timeout=0
        )

    def receive(self):
        if self.serial.in_waiting > 0:
            return self.serial.read(1).decode("ascii", errors="ignore")

        return ""
