#include <string>
#include <iostream>
#include <pcap.h>
//#include "headerFile.hpp"
std::string GetIPString(uint32_t x)
{
    char buffer[INET_ADDRSTRLEN + 1];
    auto result = inet_ntop(AF_INET, &x, buffer, sizeof(buffer));
    if (result == nullptr)
        throw std::runtime_error("Can't convert IP4 address");
    return buffer;
}
int main()
{
    std::string file = "input.pcap";

    char errbuff[PCAP_ERRBUF_SIZE];

    // libpcap'i offline modda yani dosyadan çalışacak şekilde başlatıyoruz
    pcap_t *pcap = pcap_open_offline(file.c_str(), errbuff);

    // alınacak paketin başlığı için header tanımlaması
    struct pcap_pkthdr *header;

    const u_char *data;

    u_int packetCount = 0;
    while (pcap_next_ex(pcap, &header, &data) >= 0)
    {

        std::cout << " Packet : " << ++packetCount << std::endl;

        std::cout << " Packet size : " << header->len << std::endl;

        // Show Epoch Time
        std::cout << " Epoch Time: " << header->ts.tv_sec << "." << header->ts.tv_usec << " sn" << std::endl;

        std::cout << " Destination Mac Address : ";
        for (u_int i = 0; i < 6; i++)
        {
            std::cout << std::hex << ((int)data[0] < 10 ? "0" : "") << (int)data[0] << (i != 5 ? ":" : "");
            data++;
        }
        std::cout << std::endl;

        std::cout << " Source Mac Address : ";
        for (u_int i = 0; i < 6; i++)
        {
            std::cout << std::hex << ((int)data[0] < 10 ? "0" : "") << (int)data[0] << (i != 5 ? ":" : "");
            data++;
        }
        std::cout << std::dec << std::endl;

        unsigned short ethernet_type = data[0] << 8 | data[1];
        data += 2; // **** ethernet type is 2 byte ****

        std::cout << " Ethernet Type : " << (ethernet_type == 0x0800 ? "*** IP ***" : "-----") << std::endl;

        if (ethernet_type == 0x0800)
        {
            unsigned char lms = data[2];
            unsigned char rms = data[3];

            uint16_t totallength = (lms << 8) | rms;

            lms = data[4];
            rms = data[5];
            unsigned short identification = (lms << 8) | rms;

            unsigned int ip_source = (data[15] << 24) | (data[14] << 16) | (data[13] << 8) | data[12];
            unsigned int ip_destination = (data[19] << 24) | (data[18] << 16) | (data[17] << 8) | data[16];
            std::cout << " IP Packet Total length : " << totallength << std::endl;
            std::cout << " IP identification number : " << identification << std::endl;
            std::cout << " IP Source: " << GetIPString(ip_source) << std::endl;
            std::cout << " IP Destination: " << GetIPString(ip_destination) << std::endl;
        }

        std::cout << std::endl
                  << std::endl;

        //if (packetCount == 4)
         //   break;
    }

    std::cin.get();
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////

// #include <string>
// #include <iostream>
// #include <pcap.h>
// #include "headerFile.hpp"

// using namespace std;
// int main(int argc, char *argv[])
// {
//     string file = "testp2.pcap";    //* Step 2 - Get a file name
//     char errbuff[PCAP_ERRBUF_SIZE]; // Step 3 - Create an char array to hold the error.
//     //* Step 4 - Open the file and store result in pointer to pcap_t
//     pcap_t *pcap = pcap_open_offline(file.c_str(), errbuff); // Use pcap_open_offline
//     //* Step 5 - Create a header and a data object
//     struct pcap_pkthdr *header; // Create a header object:
//     const u_char *packet;       //
//     FILE *fp = fopen("result.txt", "w");
//     const struct sniff_ethernet *ethernet; /* The ethernet header */
//     const struct sniff_ip *ip;             /* The IP header */
//     const struct sniff_tcp *tcp;           /* The TCP header */
//     u_int size_ip;
//     int i = 1;
//     char sourceIP[INET_ADDRSTRLEN];
//     char destIP[INET_ADDRSTRLEN];
//     while (pcap_next_ex(pcap, &header, &packet) >= 0)
//     {
//         printf("%d paket:", i);
//         // printf("Packet # %i\n", ++packetCount);         // Show the packet number
//         printf("Packet size: %d bytes ", header->len); // Show the size in bytes of the packet
//         if (header->len != header->caplen)             // Show a warning if the length captured is different
//             printf("Warning! Capture size different than packet size: %d bytes\n", header->len);

//         ethernet = (struct sniff_ethernet *)(packet);
//         ip = (struct sniff_ip *)(packet + SIZE_ETHERNET);
//         size_ip = IP_HL(ip) * 4;
//         i++;

//         tcp = (struct sniff_tcp *)(packet + SIZE_ETHERNET + size_ip);
//         inet_ntop(AF_INET, &(ip->ip_src), sourceIP, INET_ADDRSTRLEN);
//         inet_ntop(AF_INET, &(ip->ip_dst), destIP, INET_ADDRSTRLEN);

//         printf("\tsrc address: %s \tdest address: %s \n", sourceIP, destIP);

//         //printf("\tsrc address: %s \tdest address: %s \n", inet_ntoa(ip->ip_src), inet_ntoa(ip->ip_dst));
//         //fprintf(fp, "src address: %s \tdest address: %s \n", inet_ntoa(ip->ip_src), inet_ntoa(ip->ip_dst));
//     }
//     fclose(fp);
// }