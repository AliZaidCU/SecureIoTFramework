# replay_attack.py
# Secure IoT Framework replay attack simulation

from scapy.all import *

def replay_packet(pcap_file, iface):
    packets = rdpcap(pcap_file)
    for pkt in packets:
        sendp(pkt, iface=iface)
        print(f"Replayed packet: {pkt.summary()}")

if __name__ == "__main__":
    # Example usage: replay_packet("capture.pcap", "eth0")
    print("Replay attack simulation. Edit this script to specify your pcap file and interface.") 