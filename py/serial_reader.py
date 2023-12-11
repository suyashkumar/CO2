"""
This is a very simple program to read (hopefully) JSON from the serial console,
add timestamp data, and write out to disk.
"""
import serial
import json
import datetime

def main():
    ser = serial.Serial('/dev/cu.usbmodem14701', 115200)
    with open('data.ndjson', 'a') as fd:
        while True:
            line = ser.readline()
            try:
                data = json.loads(line)
            except ValueError as e:
                print(f"Non JSON console data: {line}")
                continue
            data['time'] = datetime.datetime.now().__str__()
            data_with_time = json.dumps(data)
            print(data_with_time)
            fd.write(data_with_time + "\n")


if __name__ == "__main__":
    main()
