# sniff.py
# Secure IoT Framework packet sniffing simulation

from scapy.all import *

def packet_callback(pkt):
    print(pkt.summary())

if __name__ == "__main__":
    print("Starting packet sniffer...")
    sniff(prn=packet_callback, count=10)  # Sniff 10 packets for demo 