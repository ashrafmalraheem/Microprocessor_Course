import os
import datetime        
def getPortsList():
    ''' Function that read the available opened COM ports and return the list of devices '''
    from serial.tools import list_ports
    port_list = list_ports.comports()
    return_list = []
    for port in port_list:
        return_list.append(port.device)
        ''' return list of str '''
    return return_list    

def openPortsList(portsList):
    ''' function to open list of ports with specified baudrate, no. of bits, parity. It returns the list of serial
        classes '''
    import serial
    from serial import Serial
    serialList = []
    BAUD_RATE = 19200
    try:
        for port in portsList:
            serialList.append(Serial(port,baudrate=BAUD_RATE, bytesize=serial.SEVENBITS, parity=serial.PARITY_EVEN,
                                    stopbits=serial.STOPBITS_ONE, timeout=0.050, exclusive = None))
            print(port, "Opened!")
    except:
        print('No port to open')
    return serialList       
        
def listSub(a,b):
    difference = []
    for i in a:
        if i not in b:
            difference.append(i)
    return difference
def readFromPorts(log_file):
    from datetime import datetime
    from time import sleep
    import serial
    TX_BUFFER_MAX_SIZE = 1000
    readlog = {}
    portList = openPortsList(getPortsList())
    while True :
        try:
            for port in portList:
                readlog[port.port] = str(port.read_until(b'\n',size = TX_BUFFER_MAX_SIZE),'utf-8').strip('\n')
                if readlog[port.port] != '':
                    print(port.port,datetime.now(),readlog[port.port],file=log_file)
                    print(port.port,datetime.now(),readlog[port.port])
                    
                    
        except UnicodeError as decode_error:
            print('Decoding Error:',decode_error)
        except serial.serialutil.SerialException as e:
            print(port.port,'Is lost ')
            ''' Close and remove the Lost port '''
            port.close()
            portList.remove(port)
        except KeyboardInterrupt:
            i = input('Do you Whant to Stop? ')
            i = i.lower()
            if i == 'stop' or i == 'y' or i == 'yes':
                print('Stopping.....')
                break
        if not (datetime.now().second % 10):
            ''' Every x seconds search for new ports that available and open them '''
            oldPortList = []
            for port in portList:
                oldPortList.append(port.port)
            newPortList = getPortsList()
            newOpenPorts = listSub(newPortList, oldPortList)
            if  len(newOpenPorts):
                portList += openPortsList(newOpenPorts)
                
       
def logging(log_file):
    try:
        readFromPorts(log_file)
    except Exception as e:
        print('Exception:',e)
 
''' Logging Directory and File'''
DIR = "Logs/"
if not os.path.exists(DIR):
    os.makedirs(DIR)
Log_file_name = DIR + "Log_" + str(datetime.date.today()) + ".log"
''' Continue reading until a keyboard is pressed '''
def mainFunction():
    try:
        with open(Log_file_name,'a+',1) as log_file:
            logging(log_file)
    except:
        with open(Log_file_name,'w+',1) as log_file:
            logging(log_file)
while True:
    mainFunction()
    i = str(input('Exit or Resume?  ')).lower()
    if i == 'exit':
        exit()
    elif i == 'resume':
        continue
