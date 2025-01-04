def ip_address(ip):
        first_oct = int(ip.split('.')[0])
        if 0<=first_oct<=127:
                return "A"
        elif 128<=first_oct<=191:
                return "B"
        elif 192<=first_oct<=223:
                return "C"
        elif 224<=first_oct<=239:
                return "D"
        elif 240<=first_oct<=255:
                return "E"
        else:
                return "Invalid"
        
ip = input("Please enter the ip address: ")
print(ip_address(ip))