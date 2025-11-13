# COMPUTER NETWORKS - COMPREHENSIVE NOTES
## BCA 4th Semester | Course Code: C4005

---

## UNIT 1: BASIC CONCEPTS AND TERMINOLOGY

### 1.1 Introduction to Computer Networks

**What is a Computer Network?**
A computer network is an interconnection of multiple devices (nodes) that can communicate and share resources with each other. These devices include computers, servers, printers, routers, switches, and other hardware connected through wired or wireless transmission media.

**Need for Computer Networks:**
- **Resource Sharing**: Share hardware (printers, scanners), software, and data
- **Communication**: Email, video conferencing, instant messaging
- **Reliability**: Alternative sources if one fails (redundancy)
- **Cost Reduction**: Shared resources reduce overall costs
- **Scalability**: Easy to add new devices
- **Performance**: Distributed processing increases efficiency

**Goals of Computer Networks:**
1. Resource sharing and utilization
2. High reliability through redundancy
3. Cost-effectiveness
4. Communication medium
5. Scalability and flexibility

---

### 1.2 OSI Model (Open Systems Interconnection Model)

The OSI model is a conceptual framework developed by ISO (International Organization for Standardization) in 1984 that standardizes network communication into seven distinct layers.

#### **Layer 7 - Application Layer**
- **Function**: Provides network services directly to end-users
- **Protocols**: HTTP, HTTPS, FTP, SMTP, DNS, TELNET, SNMP
- **Services**:
  - File transfer and access
  - Email services
  - Directory services
  - Network virtual terminal
- **Example**: When you open a web browser, the application layer handles the HTTP request

#### **Layer 6 - Presentation Layer**
- **Function**: Data translation, encryption, and compression
- **Key Responsibilities**:
  - **Translation**: Converts data formats (ASCII to EBCDIC)
  - **Encryption/Decryption**: Secures data for transmission
  - **Compression**: Reduces data size for efficient transmission
- **Formats**: JPEG, MPEG, GIF, MIDI
- **Example**: Converting a Word document to PDF format

#### **Layer 5 - Session Layer**
- **Function**: Establishes, manages, and terminates connections (sessions)
- **Key Functions**:
  - **Session establishment**: Authentication and authorization
  - **Synchronization**: Adds checkpoints (synchronization points) in data stream
  - **Dialog Control**: Half-duplex or full-duplex communication
  - **Session termination**: Graceful closure
- **Protocols**: NetBIOS, RPC, PPTP
- **Example**: Video conferencing maintaining continuous connection

#### **Layer 4 - Transport Layer**
- **Function**: End-to-end reliable data delivery and error recovery
- **Key Functions**:
  - **Segmentation**: Divides data into segments
  - **Flow Control**: Manages data transmission rate
  - **Error Control**: Detects and retransmits lost/corrupted segments
  - **Connection Management**: Establishes and terminates connections
- **Protocols**: TCP (reliable), UDP (unreliable but fast)
- **Port Numbers**: Identifies specific applications
- **Example**: TCP ensures all packets of your email reach destination in order

#### **Layer 3 - Network Layer**
- **Function**: Routing and logical addressing (IP addressing)
- **Key Functions**:
  - **Logical Addressing**: IP addresses for source and destination
  - **Routing**: Determines best path through network
  - **Packetizing**: Encapsulates segments into packets
  - **Fragmentation**: Breaks packets into smaller fragments if needed
- **Protocols**: IP (IPv4, IPv6), ICMP, IGMP, ARP, RARP
- **Devices**: Routers, Layer 3 switches
- **Example**: Your data packet finding route from India to USA servers

#### **Layer 2 - Data Link Layer**
- **Function**: Node-to-node data transfer and error detection
- **Sub-layers**:
  - **LLC (Logical Link Control)**: Error control, flow control, framing
  - **MAC (Media Access Control)**: Physical addressing, access control
- **Key Functions**:
  - **Framing**: Encapsulates packets into frames
  - **Physical Addressing**: MAC addresses
  - **Error Detection**: CRC, checksums
  - **Access Control**: CSMA/CD, CSMA/CA
- **Protocols**: Ethernet, PPP, HDLC, Frame Relay
- **Devices**: Switches, Bridges
- **Example**: Your computer's network card using MAC address to communicate with router

#### **Layer 1 - Physical Layer**
- **Function**: Transmission of raw bit stream over physical medium
- **Key Functions**:
  - **Bit Synchronization**: Clock synchronization
  - **Bit Rate Control**: Transmission rate
  - **Physical Topologies**: Bus, star, ring, mesh
  - **Transmission Mode**: Simplex, half-duplex, full-duplex
  - **Signal Encoding**: Digital to analog conversion
- **Components**: Cables, hubs, repeaters, network adapters
- **Media**: Twisted pair, coaxial cable, fiber optic, wireless
- **Example**: Electrical signals traveling through Ethernet cable

**Data Encapsulation in OSI Model:**
- Application/Presentation/Session → **Data**
- Transport Layer → **Segment** (adds port numbers)
- Network Layer → **Packet** (adds IP addresses)
- Data Link Layer → **Frame** (adds MAC addresses)
- Physical Layer → **Bits** (converted to signals)

---

### 1.3 TCP/IP Model (Transmission Control Protocol/Internet Protocol)

The TCP/IP model is a practical, implementation-based model developed by DARPA (Department of Defense) in the 1970s. It has 4 layers compared to OSI's 7 layers.

#### **Layer 4 - Application Layer**
- **Equivalent to**: OSI Layers 5, 6, and 7
- **Function**: Combines application, presentation, and session functionalities
- **Key Protocols**:
  - **HTTP/HTTPS**: Web browsing (port 80/443)
  - **FTP**: File transfer (port 20/21)
  - **SMTP**: Email sending (port 25)
  - **DNS**: Domain name resolution (port 53)
  - **TELNET**: Remote login (port 23)
  - **SNMP**: Network management (port 161/162)
  - **DHCP**: Dynamic IP assignment (port 67/68)

#### **Layer 3 - Transport Layer**
- **Equivalent to**: OSI Layer 4
- **Key Protocols**:

  **TCP (Transmission Control Protocol)**:
  - Connection-oriented
  - Reliable delivery with acknowledgments
  - Flow control and congestion control
  - Three-way handshake: SYN → SYN-ACK → ACK
  - Used for: HTTP, FTP, SMTP, email
  - Slower but guaranteed delivery

  **UDP (User Datagram Protocol)**:
  - Connectionless
  - Unreliable, no acknowledgments
  - No flow control or congestion control
  - Low overhead, fast transmission
  - Used for: DNS, DHCP, video streaming, VoIP, online gaming
  - Fast but no delivery guarantee

#### **Layer 2 - Internet Layer**
- **Equivalent to**: OSI Layer 3
- **Key Protocols**:

  **IP (Internet Protocol)**:
  - IPv4: 32-bit addressing (4.3 billion addresses)
  - IPv6: 128-bit addressing (340 undecillion addresses)
  - Provides logical addressing and routing

  **ICMP (Internet Control Message Protocol)**:
  - Error reporting and diagnostic functions
  - Used by ping and traceroute commands

  **ARP (Address Resolution Protocol)**:
  - Maps IP addresses to MAC addresses

  **RARP (Reverse ARP)**:
  - Maps MAC addresses to IP addresses

#### **Layer 1 - Network Access Layer**
- **Equivalent to**: OSI Layers 1 and 2
- **Function**: Handles physical transmission and data link protocols
- **Technologies**: Ethernet, Wi-Fi, PPP, Token Ring

**OSI vs TCP/IP Comparison:**

| Feature | OSI Model | TCP/IP Model |
|---------|-----------|--------------|
| Layers | 7 | 4 |
| Development | ISO (theoretical) | DARPA (practical) |
| Approach | Protocol-independent | Protocol-specific |
| Usage | Teaching concept | Internet standard |
| Layer distinction | Clear separation | Combined layers |

---

### 1.4 Services in Computer Networks

#### **Types of Network Services:**

**1. Connection-Oriented Service**
- Establishes connection before data transfer
- Three phases: Connection establishment → Data transfer → Connection termination
- Example: TCP, telephone call
- Reliable, guaranteed delivery
- Higher overhead

**2. Connectionless Service**
- No connection establishment
- Each packet treated independently
- Example: UDP, postal mail
- Unreliable, no guarantee
- Lower overhead, faster

**3. Acknowledged Service**
- Sender receives acknowledgment for each packet
- Ensures reliability
- Example: TCP acknowledgments

**4. Unacknowledged Service**
- No acknowledgment sent
- Faster but less reliable
- Example: UDP transmission

---

### 1.5 Network Standards

Standards ensure interoperability between devices from different manufacturers.

#### **Major Standards Organizations:**

**1. ISO (International Organization for Standardization)**
- Develops OSI model
- Global standards across industries

**2. ITU (International Telecommunication Union)**
- Standards for telecommunications
- Example: V.32, V.90 modem standards

**3. IEEE (Institute of Electrical and Electronics Engineers)**
- **802.3**: Ethernet standards
- **802.11**: Wi-Fi standards (a/b/g/n/ac/ax)
- **802.15**: Bluetooth and wireless PAN
- **802.16**: WiMAX

**4. IETF (Internet Engineering Task Force)**
- Develops Internet standards
- RFC (Request for Comments) documents
- Standards: TCP/IP, HTTP, FTP

**5. ANSI (American National Standards Institute)**
- US-based standards
- ANSI C, FDDI standards

**6. W3C (World Wide Web Consortium)**
- Web standards: HTML, CSS, XML

**Common Network Standards:**
- **Ethernet (IEEE 802.3)**: Wired LAN standard
- **Wi-Fi (IEEE 802.11)**: Wireless LAN
- **Bluetooth (IEEE 802.15)**: Personal area network
- **TCP/IP**: Internet protocol suite
- **USB**: Universal Serial Bus for peripheral connections

---

## UNIT 2: COMPUTER NETWORK

### 2.1 Network Topology

Network topology refers to the physical or logical arrangement of nodes and connections in a network.

#### **Types of Network Topologies:**

#### **1. Bus Topology**
- **Structure**: All devices connected to a single cable (backbone)
- **Advantages**:
  - Easy to install and extend
  - Requires less cable (cost-effective)
  - Suitable for small networks
- **Disadvantages**:
  - Single point of failure (backbone cable)
  - Performance degrades with more devices
  - Difficult to troubleshoot
  - Limited cable length
- **Use Case**: Small LANs, temporary networks

#### **2. Star Topology**
- **Structure**: All devices connected to a central hub/switch
- **Advantages**:
  - Easy to install and manage
  - Failure of one device doesn't affect others
  - Easy to detect and isolate faults
  - Easy to add/remove devices
  - Better performance than bus
- **Disadvantages**:
  - Central hub failure brings down entire network
  - Requires more cable than bus
  - Hub/switch cost adds up
- **Use Case**: Most common in modern LANs, home networks

#### **3. Ring Topology**
- **Structure**: Devices connected in a circular fashion
- **Types**:
  - **Single Ring**: One ring
  - **Dual Ring**: Two counter-rotating rings (FDDI)
- **Advantages**:
  - Equal access for all devices
  - No collision (token passing)
  - Predictable performance
- **Disadvantages**:
  - Single device/cable failure can break the entire ring
  - Difficult to add/remove devices
  - Troubleshooting is complex
- **Use Case**: Token Ring networks (older), FDDI

#### **4. Mesh Topology**
- **Structure**: Every device connected to every other device
- **Types**:
  - **Full Mesh**: n(n-1)/2 connections for n devices
  - **Partial Mesh**: Some devices have all connections, others don't
- **Advantages**:
  - Highly reliable (multiple paths)
  - No traffic congestion
  - Fault identification is easy
  - Secure (dedicated links)
- **Disadvantages**:
  - Very expensive (cables and ports)
  - Complex installation and maintenance
  - Space and bulk wiring issues
- **Use Case**: Internet backbone, military networks, critical systems

#### **5. Tree/Hierarchical Topology**
- **Structure**: Hybrid of star and bus, hierarchical structure
- **Advantages**:
  - Scalable (easy to expand)
  - Error detection is easy
  - Grouping possible (departments)
- **Disadvantages**:
  - Root node failure affects entire network below
  - More cables required
  - Complex maintenance
- **Use Case**: Corporate networks, university campuses

#### **6. Hybrid Topology**
- **Structure**: Combination of two or more topologies
- **Example**: Star-Bus, Star-Ring
- **Advantages**:
  - Flexible and reliable
  - Scalable
  - Fault tolerance
- **Disadvantages**:
  - Complex design
  - Expensive
- **Use Case**: Large enterprise networks

---

### 2.2 Performance of Network

Network performance is measured by several key metrics:

#### **1. Bandwidth**
- **Definition**: Maximum data transfer rate of a network path
- **Unit**: bps (bits per second), Kbps, Mbps, Gbps
- **Types**:
  - **Theoretical Bandwidth**: Maximum possible rate
  - **Effective Bandwidth**: Actual achieved rate
- **Example**: 100 Mbps Ethernet connection

#### **2. Throughput**
- **Definition**: Actual rate of successful data transfer
- **Always**: Throughput ≤ Bandwidth
- **Factors Affecting**: Network congestion, protocol overhead, hardware limitations
- **Example**: 100 Mbps link may have 80 Mbps throughput

#### **3. Latency (Delay)**
- **Definition**: Time taken for data to travel from source to destination
- **Components**:
  - **Propagation Delay**: Time for signal to travel through medium
  - **Transmission Delay**: Time to push all bits onto wire
  - **Processing Delay**: Time for router/switch to process packet
  - **Queuing Delay**: Time packet waits in queue
- **Formula**: Total Latency = Propagation + Transmission + Processing + Queuing
- **Unit**: Milliseconds (ms)
- **Example**: 30ms ping time to server

#### **4. Jitter**
- **Definition**: Variation in packet arrival time
- **Impact**: Critical for real-time applications (VoIP, video calls)
- **Cause**: Network congestion, routing changes
- **Measurement**: Standard deviation of latency

#### **5. Packet Loss**
- **Definition**: Percentage of packets that fail to reach destination
- **Causes**: Network congestion, buffer overflow, hardware errors
- **Impact**: Retransmissions, poor quality
- **Acceptable**: <1% for most applications

#### **6. Error Rate**
- **Definition**: Ratio of corrupted bits to total transmitted bits
- **Unit**: BER (Bit Error Rate)
- **Formula**: BER = (Number of errors / Total bits transmitted)

#### **7. Utilization**
- **Definition**: Percentage of bandwidth actually used
- **Formula**: (Throughput / Bandwidth) × 100%
- **Optimal**: 60-70% (above 80% causes congestion)

---

### 2.3 Network Classification

Networks are classified based on geographical coverage:

#### **1. PAN (Personal Area Network)**
- **Range**: 1-10 meters (within personal space)
- **Technologies**: Bluetooth, USB, IrDA, Zigbee
- **Devices**: Smartphone, laptop, smartwatch, wireless mouse, headphones
- **Data Rate**: 1-24 Mbps
- **Example**: Connecting phone to Bluetooth speaker

#### **2. LAN (Local Area Network)**
- **Range**: Up to 1 km (building, campus)
- **Technologies**: Ethernet (802.3), Wi-Fi (802.11)
- **Topology**: Star, bus, tree
- **Data Rate**: 10 Mbps - 10 Gbps
- **Ownership**: Private (single organization)
- **Characteristics**:
  - High data rate
  - Low latency
  - Limited geographical area
  - Owned by single entity
- **Example**: Office network, home Wi-Fi, computer lab

**LAN Protocols:**
- **Ethernet**: IEEE 802.3 standard
- **Token Ring**: IEEE 802.5 (obsolete)
- **Wi-Fi**: IEEE 802.11 (a/b/g/n/ac/ax)

#### **3. MAN (Metropolitan Area Network)**
- **Range**: 10-100 km (city-wide)
- **Technologies**: Fiber optic, WiMAX, cable modems
- **Purpose**: Interconnect multiple LANs within a city
- **Data Rate**: 10 Mbps - 100 Gbps
- **Ownership**: Public or private
- **Example**: Cable TV network, city-wide Wi-Fi, bank branches in a city

#### **4. WAN (Wide Area Network)**
- **Range**: Countries, continents (unlimited)
- **Technologies**: Leased lines, satellite, MPLS, fiber optics
- **Data Rate**: 56 Kbps - 100 Gbps
- **Ownership**: Multiple organizations, ISPs
- **Characteristics**:
  - Lower data rate than LAN
  - Higher latency
  - Uses public/leased infrastructure
  - Expensive
- **Example**: Internet (largest WAN), corporate networks connecting offices globally

**WAN Technologies:**
- **Leased Lines**: Dedicated point-to-point connection
- **Circuit Switching**: PSTN, ISDN
- **Packet Switching**: X.25, Frame Relay, ATM
- **Cell Switching**: ATM

#### **5. Other Network Types**

**CAN (Campus Area Network)**
- Interconnects LANs within a campus
- Range: 1-5 km
- Example: University network

**SAN (Storage Area Network)**
- High-speed network for storage devices
- Example: Data center storage systems

**VPN (Virtual Private Network)**
- Secure connection over public network
- Creates encrypted tunnel
- Example: Remote employee accessing company network

---

### 2.4 Advantages and Disadvantages of Networks

#### **Advantages:**

1. **Resource Sharing**
   - Share expensive hardware (printers, scanners)
   - Share software licenses
   - Share data and files

2. **Communication**
   - Email, instant messaging
   - Video conferencing
   - Voice over IP (VoIP)

3. **Cost Reduction**
   - Shared resources reduce duplication
   - Centralized management
   - Bulk licensing discounts

4. **Reliability**
   - Data backup and redundancy
   - Alternative servers if one fails
   - Fault tolerance

5. **Scalability**
   - Easy to add new devices
   - Modular expansion
   - Growing with organizational needs

6. **Flexibility**
   - Access from anywhere (remote access)
   - Mobile workforce support
   - Cloud integration

7. **Centralized Administration**
   - Central data storage
   - Easier security management
   - Centralized backup

8. **Performance**
   - Distributed processing
   - Load balancing
   - Faster data access

#### **Disadvantages:**

1. **Security Threats**
   - Viruses, malware, ransomware
   - Unauthorized access
   - Data breaches
   - Hacking attempts

2. **Dependence on Server**
   - Server failure affects all users
   - Single point of failure (in some topologies)

3. **Setup Cost**
   - Initial hardware investment
   - Cabling and infrastructure
   - Professional installation needed

4. **Maintenance**
   - Requires trained personnel
   - Regular updates and patches
   - Hardware replacement costs

5. **Data Privacy**
   - Sensitive data exposure risk
   - Need for strict access controls
   - Compliance requirements

6. **Network Failure Impact**
   - Entire organization can be affected
   - Productivity loss
   - Business disruption

7. **Complexity**
   - Troubleshooting can be difficult
   - Multiple protocols and standards
   - Configuration challenges

---

### 2.5 Transmission Media

Transmission media carries data from sender to receiver. Divided into two categories:

#### **A. Guided Media (Wired)**

#### **1. Twisted Pair Cable**

**Structure**: Two insulated copper wires twisted together

**Types:**

**a) UTP (Unshielded Twisted Pair)**
- No shielding
- Categories: Cat3, Cat5, Cat5e, Cat6, Cat6a, Cat7
- **Cat5e**: 100 Mbps, 100m, most common
- **Cat6**: 1 Gbps, 100m, modern standard
- **Advantages**: Cheap, easy to install, flexible
- **Disadvantages**: Limited distance, susceptible to interference
- **Use**: Ethernet LANs, telephone lines

**b) STP (Shielded Twisted Pair)**
- Metal foil/braided shield
- Better noise immunity
- More expensive than UTP
- **Use**: Industrial environments, high EMI areas

**Characteristics:**
- **Bandwidth**: 1 MHz - 600 MHz
- **Distance**: Up to 100 meters
- **Connector**: RJ-45 (8P8C)
- **Cost**: Low to moderate

#### **2. Coaxial Cable**

**Structure**: Central conductor, insulation, metal shield, outer jacket

**Types:**
- **Thin Coax (10Base2)**: RG-58, 10 Mbps, 185m
- **Thick Coax (10Base5)**: RG-8, 10 Mbps, 500m

**Advantages:**
- Higher bandwidth than twisted pair
- Better noise immunity
- Longer distance

**Disadvantages:**
- More expensive than twisted pair
- Difficult to install and maintain
- Bulky and less flexible

**Use Cases:**
- Cable TV (CATV)
- Older Ethernet networks
- Broadband internet (cable modems)

**Characteristics:**
- **Bandwidth**: Up to 750 MHz
- **Distance**: Up to 500 meters
- **Connector**: BNC, F-type

#### **3. Fiber Optic Cable**

**Structure**: Glass/plastic core, cladding, buffer, jacket

**Principle**: Total internal reflection of light

**Types:**

**a) Single Mode Fiber (SMF)**
- Core diameter: 8-10 microns
- Single light ray path
- Laser light source
- **Distance**: Up to 100 km without repeater
- **Bandwidth**: Very high (100+ Gbps)
- **Cost**: Expensive
- **Use**: Long-distance, backbone, ISP networks

**b) Multimode Fiber (MMF)**
- Core diameter: 50-62.5 microns
- Multiple light ray paths
- LED light source
- **Distance**: Up to 2 km
- **Bandwidth**: Lower than SMF
- **Cost**: Less expensive than SMF
- **Use**: LAN, data centers, campus networks

**Advantages:**
- Extremely high bandwidth
- Long distance transmission
- Immunity to EMI/RFI
- Secure (difficult to tap)
- Lightweight
- No electrical spark risk

**Disadvantages:**
- Very expensive
- Fragile (glass)
- Complex installation (requires skilled technicians)
- Difficult splicing and termination
- Unidirectional (need two cables for full duplex)

**Use Cases:**
- Internet backbone
- Submarine cables
- Data centers
- High-speed networks

**Characteristics:**
- **Bandwidth**: THz (terahertz)
- **Distance**: 100+ km
- **Connector**: SC, ST, LC, FC
- **Data Rate**: 10 Gbps to 100 Tbps

---

#### **B. Unguided Media (Wireless)**

#### **1. Radio Waves**
- **Frequency**: 3 KHz - 1 GHz
- **Propagation**: Omnidirectional
- **Penetration**: Can penetrate walls
- **Distance**: Long range
- **Use**: AM/FM radio, TV broadcast, paging
- **Examples**: Wi-Fi (2.4 GHz), Bluetooth, cellular networks

#### **2. Microwaves**
- **Frequency**: 1 GHz - 300 GHz
- **Propagation**: Unidirectional (line of sight)
- **Penetration**: Cannot penetrate obstacles
- **Distance**: Long distance with repeaters

**Types:**
**a) Terrestrial Microwave**
- Tower-based transmission
- **Distance**: 50 km per hop
- **Use**: Telecom backbone, mobile networks
- **Frequency**: 4-6 GHz, 21-23 GHz

**b) Satellite Microwave**
- Space-based transponders
- **Types**:
  - **GEO** (Geostationary): 36,000 km, TV broadcast
  - **MEO** (Medium Earth Orbit): 5,000-12,000 km, GPS
  - **LEO** (Low Earth Orbit): 500-2,000 km, Iridium
- **Use**: TV broadcast, GPS, internet, military

**Characteristics:**
- **Advantages**: Long distance, high bandwidth
- **Disadvantages**: Line of sight required, weather affected
- **Latency**: GEO satellites have ~240ms delay

#### **3. Infrared**
- **Frequency**: 300 GHz - 400 THz
- **Propagation**: Line of sight
- **Distance**: Short range (few meters)
- **Penetration**: Cannot penetrate walls
- **Use**: TV remotes, IrDA (mobile data transfer), wireless mouse/keyboard
- **Advantages**: Secure (confined space), license-free
- **Disadvantages**: Blocked by obstacles, interference from sunlight

---

### 2.6 Network Architecture

#### **1. Peer-to-Peer (P2P) Network**

**Structure**: All computers have equal status (peers)

**Characteristics:**
- No dedicated server
- Each computer acts as both client and server
- Decentralized
- Suitable for small networks (≤10 computers)

**Advantages:**
- Easy to setup
- Less expensive (no server needed)
- No dependency on server
- Each user controls own resources

**Disadvantages:**
- No centralized management
- Less secure
- Difficult to backup data
- Performance issues with more users
- No centralized administration

**Use Cases:**
- Home networks
- Small offices
- File sharing (BitTorrent)

#### **2. Client-Server Network**

**Structure**: Dedicated servers provide services to clients

**Components:**
- **Server**: Powerful computer providing services
- **Client**: Requests services from server
- **Services**: File, print, database, web, email servers

**Characteristics:**
- Centralized control
- Servers always on and listening
- Clients connect as needed
- Suitable for large networks

**Advantages:**
- Centralized control and management
- Better security
- Regular backups
- Scalable
- Better performance
- Resource optimization

**Disadvantages:**
- Expensive (server hardware and software)
- Requires skilled administrator
- Server failure affects all clients
- Complex setup and maintenance

**Types of Servers:**
- **File Server**: Stores and manages files
- **Print Server**: Manages print jobs
- **Web Server**: Hosts websites (Apache, IIS)
- **Database Server**: Manages databases (MySQL, Oracle)
- **Email Server**: Handles email (Exchange, Sendmail)
- **Application Server**: Runs business applications

**Use Cases:**
- Corporate networks
- Universities
- Data centers
- Internet services

---

## UNIT 3: DATA LINK LAYER

### 3.1 Need for Data Link Control

The Data Link Layer ensures reliable data transfer between two directly connected nodes over a physical link.

**Functions of Data Link Control:**

1. **Framing**
   - Divides bit stream into manageable units (frames)
   - Adds header and trailer
   - Helps in synchronization

2. **Physical Addressing**
   - Adds MAC address to frame header
   - Identifies sender and receiver

3. **Error Control**
   - Detects and corrects errors
   - Uses techniques like CRC, parity

4. **Flow Control**
   - Prevents overwhelming receiver
   - Matches sender and receiver speeds

5. **Access Control**
   - Determines which device has control over the link
   - Important in shared media

**Why Data Link Control is Needed:**
- Physical layer is unreliable (noise, attenuation, distortion)
- Frames may be corrupted during transmission
- Receiver may be slower than sender
- Multiple devices may try to access same medium

---

### 3.2 Flow Control Mechanisms

Flow control ensures sender doesn't overwhelm receiver with too much data.

#### **1. Stop-and-Wait Protocol**

**Working:**
1. Sender sends one frame
2. Sender waits for acknowledgment (ACK)
3. Receiver receives frame, sends ACK
4. Sender receives ACK, sends next frame

**Characteristics:**
- Simplest flow control mechanism
- One frame at a time
- Inefficient (idle time)

**Problems:**
- **Lost Frame**: Sender waits indefinitely → Solution: Timeout and retransmit
- **Lost ACK**: Sender retransmits → Solution: Sequence numbers (0,1)
- **Delayed ACK**: Duplicate frame received → Solution: Sequence numbers

**Efficiency:**
- Very low for long distance/high bandwidth links
- Utilization = 1 / (1 + 2a), where a = Propagation time / Transmission time

**Advantages:**
- Simple to implement
- Less buffer requirement

**Disadvantages:**
- Poor link utilization
- Unsuitable for long distance
- Idle time between transmissions

#### **2. Sliding Window Protocol**

**Working:**
- Sender can send multiple frames before waiting for ACK
- Window size determines number of frames
- Receiver acknowledges frames
- Window "slides" forward as ACKs received

**Types:**

**a) Go-Back-N ARQ**
- Sender window size: N
- Receiver window size: 1
- If error detected, receiver discards that frame and all subsequent frames
- Sender retransmits from error frame onwards

**Working:**
1. Sender transmits frames 0, 1, 2, 3...
2. If frame 2 is corrupted
3. Receiver discards frame 2, 3, 4... (all after error)
4. Receiver sends NAK(2) or doesn't send ACK
5. Sender retransmits from frame 2 onwards

**Advantages:**
- Better utilization than Stop-and-Wait
- Simple receiver (only 1 buffer)

**Disadvantages:**
- Bandwidth waste (retransmits good frames too)
- Sender needs large buffer

**b) Selective Repeat ARQ**
- Sender window size: N
- Receiver window size: N
- Only corrupted frames are retransmitted
- Receiver buffers out-of-order frames

**Working:**
1. Sender transmits frames 0, 1, 2, 3...
2. If frame 2 is corrupted
3. Receiver buffers frames 3, 4, 5...
4. Receiver sends NAK(2)
5. Sender retransmits only frame 2
6. Receiver reorders and delivers

**Advantages:**
- Most efficient protocol
- Only bad frames retransmitted
- Best bandwidth utilization

**Disadvantages:**
- Complex implementation
- Large buffer at receiver
- Sequence number management complex

**Comparison:**

| Feature | Stop-and-Wait | Go-Back-N | Selective Repeat |
|---------|---------------|-----------|------------------|
| Sender Window | 1 | N | N |
| Receiver Window | 1 | 1 | N |
| Efficiency | Poor | Good | Best |
| Complexity | Simple | Moderate | Complex |
| Retransmission | 1 frame | From error onwards | Only error frame |
| Buffer Requirement | Low | Sender: High, Receiver: Low | Both: High |

---

### 3.3 Error Detection and Correction

Errors occur during transmission due to noise, attenuation, interference, and distortion.

**Types of Errors:**

1. **Single-bit Error**: Only one bit is corrupted
   - Less common
   - Example: 00100010 → 00100110

2. **Burst Error**: Multiple consecutive bits corrupted
   - More common in real networks
   - Length = number of corrupted bits from first to last
   - Example: 00100010 → 00111110 (burst length = 4)

#### **Error Detection Techniques:**

#### **1. Parity Check**

**Simple Parity (VRC - Vertical Redundancy Check):**
- Add one parity bit to data
- **Even Parity**: Total 1s should be even
- **Odd Parity**: Total 1s should be odd

**Example (Even Parity):**
- Data: 1011001 (four 1s - even)
- Parity bit: 0
- Transmitted: 10110010

**Advantages:**
- Very simple
- Low overhead (1 bit)

**Disadvantages:**
- Can detect only odd number of errors
- Cannot detect even number of errors
- Cannot correct errors

**Two-Dimensional Parity (LRC - Longitudinal Redundancy Check):**
- Data arranged in table
- Parity calculated for rows and columns
- Can detect burst errors better

#### **2. Checksum**

**Working:**
1. Divide data into segments (usually 16-bit)
2. Add all segments using 1's complement arithmetic
3. Take 1's complement of sum
4. This is checksum
5. Append checksum to data
6. Receiver performs same calculation
7. If result is all 1s, no error

**Example:**
```
Data segments:
  10110011 01010101
  11001100 11110000
  --------+---------
Sum: 01100000 00100101
1's complement: 10011111 11011010 (Checksum)
```

**Advantages:**
- Simple to implement
- Moderate error detection capability

**Disadvantages:**
- Cannot detect all errors
- Weak for burst errors

**Use:** TCP, UDP, IP headers

#### **3. Cyclic Redundancy Check (CRC)**

**Most powerful error detection method**

**Working:**
1. Data represented as polynomial
2. Generator polynomial (divisor) agreed upon
3. Append n zeros to data (n = degree of generator)
4. Divide using modulo-2 division (XOR)
5. Remainder is CRC
6. Replace appended zeros with CRC
7. Receiver divides received data by same generator
8. If remainder is 0, no error

**Example:**
```
Data: 1101011011
Generator: 10011 (CRC-4)

1. Append 4 zeros: 11010110110000
2. Divide by 10011 using XOR
3. Remainder: 1110 (CRC)
4. Transmitted: 11010110111110
```

**Common CRC Standards:**
- **CRC-8**: 8-bit (ATM)
- **CRC-16**: 16-bit (USB, Modbus)
- **CRC-32**: 32-bit (Ethernet, ZIP)
- **CRC-CCITT**: 16-bit (Bluetooth, X.25)

**Advantages:**
- Very effective for burst errors
- Can detect errors up to burst length < degree of generator
- Industry standard
- 100% detection for specific error patterns

**Disadvantages:**
- More complex than parity/checksum
- Computation overhead

**Use Cases:**
- Ethernet frames
- Wi-Fi
- Storage devices
- File compression

#### **Error Correction Techniques:**

#### **1. Hamming Code**

**Developed by Richard Hamming (1950)**

**Key Concepts:**
- Adds redundant bits at positions that are powers of 2 (1, 2, 4, 8, 16...)
- Can detect and correct single-bit errors
- Can detect double-bit errors

**Number of redundancy bits:**
- Formula: 2^r ≥ m + r + 1
- Where m = data bits, r = redundancy bits

**Example (7,4 Hamming Code):**
- 4 data bits → 3 parity bits → 7 total bits

**Bit Positions:**
```
Position: 1  2  3  4  5  6  7
Type:     P1 P2 D1 P4 D2 D3 D4
```

**Parity Calculation:**
- P1 checks positions: 1, 3, 5, 7 (binary: XX1)
- P2 checks positions: 2, 3, 6, 7 (binary: X1X)
- P4 checks positions: 4, 5, 6, 7 (binary: 1XX)

**Data: 1011**
```
Position: 1  2  3  4  5  6  7
Content:  P1 P2 1  P4 0  1  1

P1 = XOR(3,5,7) = XOR(1,0,1) = 0
P2 = XOR(3,6,7) = XOR(1,1,1) = 1
P4 = XOR(5,6,7) = XOR(0,1,1) = 0

Transmitted: 0110011
```

**Error Detection:**
- Calculate all parities at receiver
- If all zero: No error
- If non-zero: Position of error = decimal value of parity results

**Advantages:**
- Can correct single-bit errors
- Automated correction

**Disadvantages:**
- High overhead for small data
- Only single-bit correction

#### **2. Forward Error Correction (FEC)**

- Used in noisy channels where retransmission is expensive
- Example: Satellite communication, broadcast
- Adds enough redundancy to correct errors without retransmission

---

### 3.4 Framing Methods

**Framing**: Process of dividing bit stream into discrete units (frames)

**Need for Framing:**
- Identify beginning and end of frame
- Error detection per frame
- Flow control per frame
- Addressing

**Methods:**

#### **1. Character/Byte Count**
- Frame starts with count field indicating number of characters
- Example: | 5 | A | B | C | D |
- **Problem**: If count field corrupted, synchronization lost
- Rarely used

#### **2. Character/Byte Stuffing**
- Use special characters to mark frame boundaries
- **Flag**: Start and end marker (e.g., STX, ETX)
- **Problem**: What if data contains flag character?
- **Solution**: Escape character (ESC) before flag in data
- **Example**: PPP (Point-to-Point Protocol)

#### **3. Bit Stuffing**
- Used in HDLC, SDLC protocols
- Flag: 01111110 (unique pattern)
- **Rule**: After five consecutive 1s, insert 0
- Receiver removes stuffed 0s

**Example:**
```
Original data: 011111110
After stuffing: 0111110110 (0 inserted after five 1s)
```

#### **4. Physical Layer Coding Violations**
- Use invalid signal patterns as frame delimiters
- Used in Ethernet
- Example: Manchester encoding uses special symbols

---

### 3.5 Multiple Access Protocols (MAC)

When multiple devices share a medium, access control is needed.

#### **1. ALOHA**

**Pure ALOHA:**
- Station transmits whenever data available
- If collision occurs, wait random time and retransmit
- Vulnerable time: 2 × Frame transmission time
- **Efficiency**: 18.4%

**Slotted ALOHA:**
- Time divided into slots
- Transmission only at slot beginning
- Vulnerable time: 1 × Frame transmission time
- **Efficiency**: 36.8%

#### **2. CSMA (Carrier Sense Multiple Access)**

**1-Persistent CSMA:**
- Listen before transmit
- If idle: Transmit immediately
- If busy: Wait and keep listening
- If collision: Random backoff

**Non-Persistent CSMA:**
- If idle: Transmit
- If busy: Wait random time, then listen again
- Less collision than 1-persistent

**P-Persistent CSMA:**
- Used in slotted channels
- If idle: Transmit with probability p
- Wait next slot with probability (1-p)

#### **3. CSMA/CD (Collision Detection)**

**Used in Ethernet (IEEE 802.3)**

**Working:**
1. Listen to channel (carrier sense)
2. If idle, start transmitting
3. While transmitting, keep listening
4. If collision detected, stop immediately
5. Send jam signal (48 bits)
6. Wait random backoff time (Binary Exponential Backoff)
7. Try again

**Binary Exponential Backoff:**
- After i-th collision, wait random time from {0, 1, 2, ..., 2^i - 1}
- Maximum i = 10
- After 16 attempts, give up

**Minimum Frame Size:**
- Frame transmission time ≥ 2 × Propagation time
- For Ethernet: 64 bytes minimum

**Advantages:**
- Efficient for light load
- Simple implementation

**Disadvantages:**
- Performance degrades with load
- Not suitable for wireless (hidden terminal problem)

#### **4. CSMA/CA (Collision Avoidance)**

**Used in Wi-Fi (IEEE 802.11)**

**Why not CSMA/CD in wireless?**
- Cannot detect collision while transmitting
- Hidden terminal problem
- Exposed terminal problem

**Working:**
1. Listen to channel
2. If idle for DIFS time, transmit
3. If busy, wait and use backoff
4. Receiver sends ACK if frame received correctly
5. If no ACK, assume collision and retransmit

**Additional Features:**
- **RTS/CTS (Request to Send / Clear to Send)**:
  - Sender sends RTS
  - Receiver sends CTS
  - Nearby stations defer transmission
  - Reduces hidden terminal problem

- **NAV (Network Allocation Vector)**:
  - Duration field in frames
  - Stations set timer and defer

**Interframe Spaces:**
- **SIFS (Short IFS)**: Highest priority (ACK, CTS)
- **PIFS (PCF IFS)**: Medium priority
- **DIFS (DCF IFS)**: Lowest priority (data frames)

---

## UNIT 4: NETWORK LAYER

### 4.1 Routing

**Routing**: Process of selecting paths in a network to send data from source to destination.

**Router**: Network device that forwards packets based on IP addresses.

**Key Concepts:**

**Routing Table:**
- Contains network destinations and next hop
- Built using routing protocols
- Example entry: Destination | Netmask | Gateway | Interface

**Metrics:**
- **Hop Count**: Number of routers
- **Bandwidth**: Link capacity
- **Delay**: Time to traverse
- **Load**: Traffic on link
- **Reliability**: Error rate
- **Cost**: Administrative cost

#### **Types of Routing:**

#### **1. Static Routing**

**Definition**: Routes manually configured by administrator

**Characteristics:**
- Fixed paths
- No automatic updates
- Administrator adds/removes routes

**Advantages:**
- No routing protocol overhead
- Predictable paths
- More secure
- No CPU/bandwidth for routing updates

**Disadvantages:**
- Not scalable
- No automatic failover
- Administrative overhead
- Unsuitable for large networks

**Use Cases:**
- Small networks
- Stub networks (only one path out)
- Default routes

#### **2. Dynamic Routing**

**Definition**: Routes automatically learned and updated using routing protocols

**Characteristics:**
- Automatic path discovery
- Adapts to topology changes
- Routers exchange information

**Advantages:**
- Scalable
- Automatic failover
- Less administrative work
- Adapts to changes

**Disadvantages:**
- Routing protocol overhead
- More complex
- Requires CPU and bandwidth
- Convergence time

**Routing Algorithms:**

#### **A. Distance Vector Routing**

**Principle**: Each router maintains distance (metric) to all destinations

**Working:**
1. Each router knows distance to directly connected neighbors
2. Routers periodically exchange entire routing tables with neighbors
3. Each router updates its table using Bellman-Ford algorithm
4. Process continues until convergence

**Algorithm:**
- D(x,y) = minimum cost from x to y
- D(x,y) = min{ c(x,v) + D(v,y) } for all neighbors v

**Examples:**
- **RIP (Routing Information Protocol)**:
  - Metric: Hop count (max 15)
  - Updates every 30 seconds
  - Simple but slow convergence

- **IGRP (Interior Gateway Routing Protocol)**:
  - Cisco proprietary
  - Metric: Bandwidth, delay, load, reliability

**Advantages:**
- Simple to implement
- Easy to configure

**Disadvantages:**
- Slow convergence
- **Count-to-infinity problem**:
  - When link fails, bad news spreads slowly
  - Solution: Split horizon, route poisoning, hold-down timers

#### **B. Link State Routing**

**Principle**: Each router has complete topology map

**Working:**
1. Each router discovers neighbors (HELLO packets)
2. Each router measures cost to neighbors
3. Each router broadcasts Link State Packets (LSP) to all routers
4. Each router builds complete topology database
5. Each router runs Dijkstra's algorithm to find shortest paths

**Dijkstra's Algorithm:**
1. Initialize: Source distance = 0, others = infinity
2. Select node with minimum distance (not yet processed)
3. Update distances to neighbors
4. Repeat until all nodes processed

**Examples:**
- **OSPF (Open Shortest Path First)**:
  - Metric: Cost (based on bandwidth)
  - Supports VLSM and CIDR
  - Fast convergence
  - Area concept for scalability

- **IS-IS (Intermediate System to Intermediate System)**:
  - Similar to OSPF
  - Used in ISP networks

**Advantages:**
- Fast convergence
- Accurate topology information
- Supports hierarchical design
- No count-to-infinity problem

**Disadvantages:**
- Complex implementation
- Higher memory and CPU requirements
- Initial flooding can be intensive

#### **C. Path Vector Routing**

**Example: BGP (Border Gateway Protocol)**

**Characteristics:**
- Used between autonomous systems (AS)
- Path contains sequence of AS numbers
- Policy-based routing
- Prevents loops (path contains AS already)

**Use**: Internet routing between ISPs

#### **Comparison:**

| Feature | Distance Vector | Link State |
|---------|----------------|------------|
| Knowledge | Only neighbors | Complete topology |
| Update | Periodic | Event-triggered |
| Algorithm | Bellman-Ford | Dijkstra |
| Convergence | Slow | Fast |
| Overhead | Low | High |
| Scalability | Limited | Better |
| Examples | RIP, IGRP | OSPF, IS-IS |

---

### 4.2 Congestion Control

**Congestion**: Situation where too many packets in network causes performance degradation

**Symptoms:**
- Packet loss
- Long delays
- Decreased throughput
- Retransmissions

**Causes:**
- Input rate > output capacity
- Slow processors
- Insufficient buffer space

#### **Effects of Congestion:**

1. **Goodput vs Load**:
   - Initially: Goodput increases with load
   - After congestion: Goodput decreases
   - Wasted retransmissions

2. **Delay**:
   - Exponential increase
   - Queuing delays dominate

3. **Packet Loss**:
   - Buffer overflow
   - More retransmissions
   - Worse congestion

#### **Congestion Control vs Flow Control:**

| Congestion Control | Flow Control |
|-------------------|--------------|
| Network-wide issue | Point-to-point issue |
| Prevents network overload | Prevents receiver overload |
| Involves multiple nodes | Between sender-receiver |
| Network layer | Data link/transport layer |

#### **Congestion Control Approaches:**

#### **1. Open Loop (Prevention)**

**Actions taken before congestion occurs**

**Techniques:**

**a) Retransmission Policy**:
- Selective retransmission better than Go-Back-N
- Reduces duplicate packets

**b) Acknowledgment Policy**:
- Don't ACK every packet
- Use cumulative ACKs
- Reduces ACK traffic

**c) Window Policy**:
- Smaller windows reduce congestion
- Balance throughput vs congestion

**d) Discarding Policy**:
- Which packets to discard in congestion?
- Strategies: Drop tail, random early detection

**e) Admission Control**:
- Don't allow new connections during congestion
- Used in virtual circuit networks

#### **2. Closed Loop (Detection and Recovery)**

**Actions taken after detecting congestion**

**Steps:**
1. **Detect Congestion**:
   - Monitor packet loss
   - Observe delays
   - Check queue lengths
   - Explicit signaling

2. **Inform Source**:
   - **Implicit**: Timeout, no ACK
   - **Explicit**: ICMP Source Quench, ECN (Explicit Congestion Notification)

3. **Adjust Transmission**:
   - Reduce sending rate
   - Slow start
   - Increase gradually

**Techniques:**

**a) Backpressure**:
- Congested node stops accepting packets
- Information propagates backward
- Used in virtual circuits

**b) Choke Packet**:
- Congested router sends special packet to source
- Source reduces transmission rate

**c) Implicit Signaling**:
- Source detects congestion from symptoms
- Example: TCP congestion control

**d) Explicit Signaling**:
- **Forward**: Bit set in packet going toward destination
- **Backward**: Bit set in packet going toward source

#### **TCP Congestion Control:**

**Mechanisms:**

**1. Slow Start**:
- Start with small congestion window (cwnd = 1 MSS)
- Double cwnd every RTT
- Exponential growth
- Continue until threshold

**2. Congestion Avoidance**:
- After threshold, linear growth
- cwnd += 1 MSS per RTT
- Additive increase

**3. Fast Retransmit**:
- 3 duplicate ACKs indicate loss
- Retransmit immediately
- Don't wait for timeout

**4. Fast Recovery**:
- After fast retransmit
- Set threshold = cwnd / 2
- Start congestion avoidance
- Not slow start

**TCP Tahoe vs Reno vs NewReno:**

| Algorithm | On Timeout | On 3 Dup ACKs |
|-----------|------------|---------------|
| Tahoe | Slow start | Slow start |
| Reno | Slow start | Fast recovery |
| NewReno | Slow start | Fast recovery (improved) |

---

### 4.3 Internetworking Principles

**Internetworking**: Connecting multiple networks to form an internet

**Devices:**

#### **1. Repeater** (Physical Layer)
- Regenerates signals
- Extends cable length
- No filtering
- 2 ports

#### **2. Hub** (Physical Layer)
- Multi-port repeater
- Broadcasts to all ports
- No intelligence
- Creates single collision domain

#### **3. Bridge** (Data Link Layer)
- Connects two LANs
- Filters based on MAC address
- Maintains MAC address table
- Reduces collisions
- Separates collision domains

**Types:**
- **Transparent Bridge**: Auto-learns MAC addresses
- **Source Routing Bridge**: Path determined by source

**Learning Process:**
1. Initially, table empty
2. When frame arrives, learn source MAC and port
3. Check destination MAC in table
4. If found, forward to specific port
5. If not found, flood to all ports except source

#### **4. Switch** (Data Link Layer)
- Multi-port bridge
- Fast hardware-based forwarding
- Each port is separate collision domain
- Supports full-duplex
- Uses store-and-forward or cut-through

**Types:**
- **Store-and-Forward**: Receives entire frame, checks, then forwards
- **Cut-through**: Starts forwarding after reading destination
- **Fragment-free**: Checks first 64 bytes

#### **5. Router** (Network Layer)
- Connects different networks
- Routes based on IP address
- Separates broadcast domains
- More intelligent than bridge/switch
- Slower than switch (software processing)

**Functions:**
- Packet forwarding
- Routing (path selection)
- Fragmentation/reassembly
- Logical addressing

#### **6. Gateway** (All Layers)
- Protocol converter
- Connects dissimilar networks
- Example: Email gateway, IoT gateway

**Comparison:**

| Device | Layer | Addresses | Domains |
|--------|-------|-----------|---------|
| Repeater | Physical | None | None |
| Hub | Physical | None | Single collision |
| Bridge | Data Link | MAC | Multiple collision |
| Switch | Data Link | MAC | Multiple collision |
| Router | Network | IP | Multiple broadcast |

---

### 4.4 Internet Protocol (IP)

#### **IPv4 Packet Format:**

**Header Structure (20-60 bytes):**

```
0                   1                   2                   3
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|Version|  IHL  |Type of Service|          Total Length         |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|         Identification        |Flags|      Fragment Offset    |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|  Time to Live |    Protocol   |         Header Checksum       |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                       Source Address                          |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                    Destination Address                        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                    Options (if any)                           |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
```

**Field Descriptions:**

**1. Version (4 bits)**:
- IP version number
- IPv4 = 4, IPv6 = 6

**2. IHL - Internet Header Length (4 bits)**:
- Header length in 32-bit words
- Minimum = 5 (20 bytes)
- Maximum = 15 (60 bytes)

**3. Type of Service / DiffServ (8 bits)**:
- Priority and QoS
- Precedence bits + Delay + Throughput + Reliability

**4. Total Length (16 bits)**:
- Total packet size (header + data)
- Maximum = 65,535 bytes
- Minimum = 20 bytes

**5. Identification (16 bits)**:
- Unique ID for fragmented packets
- All fragments have same ID

**6. Flags (3 bits)**:
- **Bit 0**: Reserved (always 0)
- **Bit 1 (DF)**: Don't Fragment
- **Bit 2 (MF)**: More Fragments

**7. Fragment Offset (13 bits)**:
- Position of fragment in original packet
- In units of 8 bytes

**8. Time to Live - TTL (8 bits)**:
- Hop limit
- Decremented by each router
- Packet discarded when TTL = 0
- Prevents infinite loops
- Typical value: 64 or 128

**9. Protocol (8 bits)**:
- Upper layer protocol
- 1 = ICMP, 6 = TCP, 17 = UDP

**10. Header Checksum (16 bits)**:
- Error detection for header only
- Recalculated at each hop (TTL changes)

**11. Source Address (32 bits)**:
- IP address of sender

**12. Destination Address (32 bits)**:
- IP address of receiver

**13. Options (variable)**:
- Optional features
- Security, source routing, timestamps
- Rarely used

---

### 4.5 Hierarchical Addressing & Subnetting

#### **IPv4 Address Structure:**

**32-bit address written in dotted decimal notation**
- Example: 192.168.1.1
- Binary: 11000000.10101000.00000001.00000001

**Address Classes:**

**Class A:**
- **Range**: 1.0.0.0 to 126.255.255.255
- **First bit**: 0
- **Network bits**: 8
- **Host bits**: 24
- **Networks**: 126 (2^7 - 2)
- **Hosts per network**: 16,777,214 (2^24 - 2)
- **Default mask**: 255.0.0.0 or /8
- **Use**: Very large organizations

**Class B:**
- **Range**: 128.0.0.0 to 191.255.255.255
- **First bits**: 10
- **Network bits**: 16
- **Host bits**: 16
- **Networks**: 16,384 (2^14)
- **Hosts per network**: 65,534 (2^16 - 2)
- **Default mask**: 255.255.0.0 or /16
- **Use**: Medium organizations

**Class C:**
- **Range**: 192.0.0.0 to 223.255.255.255
- **First bits**: 110
- **Network bits**: 24
- **Host bits**: 8
- **Networks**: 2,097,152 (2^21)
- **Hosts per network**: 254 (2^8 - 2)
- **Default mask**: 255.255.255.0 or /24
- **Use**: Small organizations

**Class D (Multicast):**
- **Range**: 224.0.0.0 to 239.255.255.255
- **First bits**: 1110
- **Use**: Multicast groups

**Class E (Experimental):**
- **Range**: 240.0.0.0 to 255.255.255.255
- **First bits**: 1111
- **Use**: Research and experimental

**Special Addresses:**
- **0.0.0.0**: This network
- **127.0.0.0/8**: Loopback (127.0.0.1)
- **255.255.255.255**: Broadcast to local network
- **x.x.x.0**: Network address
- **x.x.x.255**: Broadcast address (in /24)

**Private IP Addresses (RFC 1918):**
- Class A: 10.0.0.0/8
- Class B: 172.16.0.0/12 (172.16.0.0 - 172.31.255.255)
- Class C: 192.168.0.0/16 (192.168.0.0 - 192.168.255.255)

---

#### **Subnetting:**

**Purpose:**
- Divide large network into smaller subnets
- Better IP address utilization
- Improved security and management
- Reduced broadcast traffic

**How it works:**
- Borrow bits from host portion for subnet
- Create more networks with fewer hosts each

**Subnet Mask:**
- Identifies network and host portions
- 1s = Network bits, 0s = Host bits

**Example:**
```
Network: 192.168.1.0/24
Need 4 subnets

Borrow 2 bits: 2^2 = 4 subnets
New mask: /26 (255.255.255.192)
Hosts per subnet: 2^6 - 2 = 62

Subnets:
1. 192.168.1.0/26    (192.168.1.0 - 192.168.1.63)
2. 192.168.1.64/26   (192.168.1.64 - 192.168.1.127)
3. 192.168.1.128/26  (192.168.1.128 - 192.168.1.191)
4. 192.168.1.192/26  (192.168.1.192 - 192.168.1.255)
```

**Subnetting Formulas:**
- **Subnets** = 2^n (n = borrowed bits)
- **Hosts per subnet** = 2^h - 2 (h = remaining host bits)
- **-2 because**: Network address and broadcast address

**CIDR (Classless Inter-Domain Routing):**
- Removes class boundaries
- Variable Length Subnet Mask (VLSM)
- More flexible address allocation
- Route aggregation (supernetting)
- Notation: IP/prefix (e.g., 192.168.1.0/24)

**VLSM Example:**
```
Organization has 192.168.1.0/24

Department A needs 100 hosts: Use /25 (126 hosts)
- 192.168.1.0/25

Department B needs 50 hosts: Use /26 (62 hosts)
- 192.168.1.128/26

Department C needs 20 hosts: Use /27 (30 hosts)
- 192.168.1.192/27
```

---

## UNIT 5: TRANSPORT LAYER

### 5.1 Process-to-Process Delivery

**Transport Layer Functions:**
- End-to-end communication between processes
- Uses port numbers to identify processes
- Provides logical communication

**Port Numbers:**
- 16-bit identifier (0-65535)
- Identifies specific application/service

**Port Number Ranges:**

**1. Well-Known Ports (0-1023):**
- Assigned to standard services
- Requires administrator privileges
- Examples:
  - 20/21: FTP
  - 22: SSH
  - 23: Telnet
  - 25: SMTP
  - 53: DNS
  - 80: HTTP
  - 110: POP3
  - 143: IMAP
  - 443: HTTPS

**2. Registered Ports (1024-49151):**
- Registered with IANA
- Used by specific applications
- Examples:
  - 3306: MySQL
  - 5432: PostgreSQL
  - 27017: MongoDB

**3. Dynamic/Private Ports (49152-65535):**
- Used by clients temporarily
- Ephemeral ports
- Assigned automatically by OS

**Socket:**
- Combination of IP address and port number
- Uniquely identifies a process on a network
- Format: IP:Port (e.g., 192.168.1.10:80)

**Connection:**
- Identified by socket pair
- (Source IP:Port, Destination IP:Port)
- Example: (192.168.1.10:5000, 8.8.8.8:80)

---

### 5.2 TCP (Transmission Control Protocol)

**Characteristics:**
- Connection-oriented
- Reliable delivery
- Byte stream service
- Full-duplex communication
- Flow control
- Congestion control
- Error detection

#### **TCP Segment Format:**

```
0                   1                   2                   3
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|          Source Port          |       Destination Port        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                        Sequence Number                        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                    Acknowledgment Number                      |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|  Data |           |U|A|P|R|S|F|                               |
| Offset| Reserved  |R|C|S|S|Y|I|            Window             |
|       |           |G|K|H|T|N|N|                               |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|           Checksum            |         Urgent Pointer        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                    Options                    |    Padding    |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
```

**Field Descriptions:**

**1. Source Port (16 bits):** Sender's port number

**2. Destination Port (16 bits):** Receiver's port number

**3. Sequence Number (32 bits):**
- Byte number of first byte in segment
- Used for ordering and duplicate detection
- Initial value random (ISN - Initial Sequence Number)

**4. Acknowledgment Number (32 bits):**
- Next expected byte number
- Cumulative acknowledgment
- Valid only if ACK flag set

**5. Data Offset (4 bits):**
- Header length in 32-bit words
- Minimum = 5 (20 bytes)

**6. Reserved (6 bits):** Future use

**7. Control Flags (6 bits):**
- **URG**: Urgent pointer valid
- **ACK**: Acknowledgment number valid
- **PSH**: Push data to application immediately
- **RST**: Reset connection
- **SYN**: Synchronize sequence numbers (connection setup)
- **FIN**: Finish, no more data (connection termination)

**8. Window (16 bits):**
- Receiver's buffer space available
- Flow control mechanism
- Maximum = 65,535 bytes

**9. Checksum (16 bits):**
- Error detection for header and data
- Mandatory in TCP

**10. Urgent Pointer (16 bits):**
- Offset of urgent data
- Valid if URG flag set

**11. Options (variable):**
- Maximum Segment Size (MSS)
- Window scaling
- Timestamps
- Selective ACK (SACK)

---

#### **TCP Connection Establishment (Three-Way Handshake):**

```
Client                                Server
  |                                     |
  | --------- SYN (seq=x) -----------> |  (Step 1)
  |                                     |
  | <---- SYN-ACK (seq=y, ack=x+1) --- |  (Step 2)
  |                                     |
  | --------- ACK (ack=y+1) ---------> |  (Step 3)
  |                                     |
  |    Connection Established          |
```

**Steps:**

**1. Client → Server: SYN**
- SYN flag set
- Sequence number = x (random ISN)
- Client enters SYN_SENT state

**2. Server → Client: SYN-ACK**
- SYN and ACK flags set
- Sequence number = y (random ISN)
- Acknowledgment number = x + 1
- Server enters SYN_RECEIVED state

**3. Client → Server: ACK**
- ACK flag set
- Acknowledgment number = y + 1
- Both enter ESTABLISHED state

**Why Three-Way?**
- Prevents old duplicate connections
- Synchronizes sequence numbers
- Confirms both sides ready

---

#### **TCP Connection Termination (Four-Way Handshake):**

```
Client                                Server
  |                                     |
  | --------- FIN (seq=x) -----------> |  (Step 1)
  |                                     |
  | <---------- ACK (ack=x+1) --------- |  (Step 2)
  |                                     |
  | <---------- FIN (seq=y) ----------- |  (Step 3)
  |                                     |
  | --------- ACK (ack=y+1) ---------> |  (Step 4)
  |                                     |
  |    Connection Closed               |
```

**Steps:**

**1. Client → Server: FIN**
- Client wants to close
- FIN flag set
- Client enters FIN_WAIT_1 state

**2. Server → Client: ACK**
- Acknowledges FIN
- Server enters CLOSE_WAIT state
- Client enters FIN_WAIT_2 state

**3. Server → Client: FIN**
- Server ready to close
- FIN flag set
- Server enters LAST_ACK state

**4. Client → Server: ACK**
- Acknowledges FIN
- Client enters TIME_WAIT state (2MSL wait)
- Server closes immediately

**TIME_WAIT State:**
- Waits 2MSL (Maximum Segment Lifetime)
- Ensures ACK reaches server
- Allows old segments to die
- Typically 1-4 minutes

---

#### **TCP Flow Control (Sliding Window):**

**Purpose:** Prevent sender from overwhelming receiver

**Mechanism:**
- Receiver advertises window size
- Sender can send up to window size
- Window slides as data acknowledged

**Example:**
```
Receiver buffer: 10,000 bytes
Receiver receives 4,000 bytes
Available space: 6,000 bytes
Advertised window: 6,000
```

**Zero Window:**
- Receiver buffer full
- Advertises window = 0
- Sender stops sending
- Sender sends probe segments

---

#### **TCP Retransmission:**

**Timeout-based:**
- No ACK within RTO (Retransmission Timeout)
- Sender retransmits segment
- RTO dynamically calculated

**Fast Retransmit:**
- Receive 3 duplicate ACKs
- Indicates segment loss
- Retransmit immediately
- Don't wait for timeout

---

### 5.3 UDP (User Datagram Protocol)

**Characteristics:**
- Connectionless
- Unreliable
- No flow control
- No congestion control
- Simple and fast
- Low overhead (8-byte header)

#### **UDP Datagram Format:**

```
0      7 8     15 16    23 24    31
+--------+--------+--------+--------+
|     Source      |   Destination   |
|      Port       |      Port       |
+--------+--------+--------+--------+
|     Length      |    Checksum     |
+--------+--------+--------+--------+
|                                   |
|          Data (payload)           |
|                                   |
+-----------------------------------+
```

**Fields:**

**1. Source Port (16 bits):**
- Optional (can be 0)

**2. Destination Port (16 bits):**
- Required

**3. Length (16 bits):**
- Total length (header + data)
- Minimum = 8 bytes

**4. Checksum (16 bits):**
- Optional in IPv4
- Mandatory in IPv6
- Covers header, data, and pseudo-header

**When to Use UDP:**
- Speed more important than reliability
- Applications handle retransmission
- Small transactions (DNS queries)
- Real-time applications tolerating loss

**Applications:**
- **DNS**: Quick query/response
- **DHCP**: IP address assignment
- **TFTP**: Simple file transfer
- **SNMP**: Network management
- **VoIP**: Voice calls
- **Video Streaming**: Live broadcasts
- **Online Gaming**: Fast updates

---

### 5.4 TCP vs UDP Comparison

| Feature | TCP | UDP |
|---------|-----|-----|
| Connection | Connection-oriented | Connectionless |
| Reliability | Reliable | Unreliable |
| Ordering | Ordered delivery | No ordering |
| Speed | Slower | Faster |
| Header Size | 20-60 bytes | 8 bytes |
| Error Checking | Yes | Optional |
| Flow Control | Yes | No |
| Congestion Control | Yes | No |
| Retransmission | Yes | No |
| Acknowledgment | Yes | No |
| Broadcasting | No | Yes |
| Overhead | High | Low |
| Use Cases | Email, web, file transfer | DNS, video streaming, VoIP |

---

## UNIT 6: APPLICATION LAYER

### 6.1 Telnet (Telecommunication Network)

**Purpose:** Remote login to another computer

**Port:** 23 (TCP)

**Characteristics:**
- Text-based interface
- Client-server model
- Virtual terminal protocol
- Platform independent

**Working:**
1. Client connects to Telnet server
2. User authentication (username/password)
3. Commands executed on remote machine
4. Results displayed on client terminal

**Features:**
- Remote administration
- Execute commands remotely
- Access remote files and applications

**Limitations:**
- **No Encryption**: Data sent in plaintext
- **Security Risk**: Passwords visible to sniffers
- **Deprecated**: Replaced by SSH

**Commands:**
- `telnet hostname port` - Connect to host
- `quit` or `exit` - Close connection

**Use Cases:**
- Testing network services
- Checking if port is open
- Educational purposes

**Modern Alternative: SSH (Secure Shell)**
- Port 22
- Encrypted communication
- Secure authentication
- Industry standard for remote access

---

### 6.2 FTP (File Transfer Protocol)

**Purpose:** Transfer files between computers

**Ports:**
- **Port 21:** Control connection (commands)
- **Port 20:** Data connection (file transfer)

**Protocol:** TCP (reliable transfer needed)

#### **FTP Architecture:**

**Two Connections:**

**1. Control Connection:**
- Established first
- Remains open during session
- Carries commands and responses
- Persistent

**2. Data Connection:**
- Established for each file transfer
- Closes after transfer
- Temporary

#### **FTP Modes:**

**1. Active Mode:**
- Client opens random port, sends to server
- Server connects back from port 20
- **Problem:** Client firewall may block incoming

**2. Passive Mode:**
- Client initiates both connections
- Server provides port number
- **Advantage:** Works with client firewalls

#### **FTP Commands:**

**Access Control:**
- `USER` - Username
- `PASS` - Password
- `QUIT` - Logout

**File Management:**
- `LIST` - List files
- `RETR` - Retrieve (download) file
- `STOR` - Store (upload) file
- `DELE` - Delete file
- `MKD` - Make directory
- `RMD` - Remove directory

**Transfer Mode:**
- `TYPE A` - ASCII mode (text files)
- `TYPE I` - Binary mode (images, executables)
- `MODE S` - Stream mode

#### **FTP Response Codes:**

- **1xx:** Positive preliminary
- **2xx:** Positive completion (success)
  - 200: Command OK
  - 220: Service ready
  - 226: Transfer complete
- **3xx:** Positive intermediate (need more info)
  - 331: Username OK, need password
- **4xx:** Transient negative (temporary error)
  - 421: Service not available
- **5xx:** Permanent negative (permanent error)
  - 530: Not logged in
  - 550: File not available

#### **FTP Limitations:**

**Security Issues:**
- **No Encryption**: Data sent in plaintext
- **Password Exposure**: Credentials visible
- **Vulnerable to Attacks**: Sniffing, man-in-the-middle

**Modern Alternatives:**

**1. FTPS (FTP Secure):**
- FTP with SSL/TLS encryption
- Ports 989, 990

**2. SFTP (SSH File Transfer Protocol):**
- File transfer over SSH
- Port 22
- Encrypted
- More secure

**3. SCP (Secure Copy Protocol):**
- Simple file copy over SSH
- Port 22

**Use Cases:**
- Website file management
- Backup and archiving
- Large file transfers
- Software distribution

---

### 6.3 NFS (Network File System)

**Purpose:** Access files over network as if local

**Developed by:** Sun Microsystems (1984)

**Protocol:** Originally UDP, now TCP also

**Port:** 2049

**Characteristics:**
- Distributed file system
- Client-server architecture
- Transparent access
- Platform independent (mostly Unix/Linux)

**Working:**
1. NFS server exports directories
2. Clients mount exported directories
3. Files accessed using normal file operations
4. NFS translates local calls to network requests

**NFS Versions:**

**NFSv2:**
- 32-bit file sizes
- Limited to 2GB files
- UDP only

**NFSv3:**
- 64-bit file sizes
- Better performance
- TCP support

**NFSv4:**
- Stateful protocol
- Better security
- Firewall friendly (single port)
- Built-in security (Kerberos)

**Components:**

**1. NFS Server:**
- Manages shared files
- Handles client requests
- Export configuration (/etc/exports)

**2. NFS Client:**
- Mounts remote filesystems
- Makes requests to server

**3. RPC (Remote Procedure Call):**
- Communication mechanism
- Port mapper (portmapper/rpcbind)

**Advantages:**
- Transparent file access
- Centralized storage
- Easy sharing
- Reduced local storage needs

**Disadvantages:**
- Network dependency
- Performance over WAN
- Security concerns (older versions)
- Single point of failure

**Use Cases:**
- Home directories in organizations
- Shared application data
- Diskless workstations
- Unix/Linux environments

---

### 6.4 SMTP (Simple Mail Transfer Protocol)

**Purpose:** Send email from client to server and between servers

**Port:**
- **25:** SMTP (server-to-server)
- **587:** Submission (client-to-server with auth)
- **465:** SMTPS (deprecated, now uses STARTTLS)

**Protocol:** TCP

**Characteristics:**
- Text-based protocol
- Push protocol (sends email)
- ASCII characters only (originally)
- Relay mechanism

#### **Email Architecture:**

**Components:**

**1. MUA (Mail User Agent):**
- Email client (Outlook, Gmail, Thunderbird)
- Composes and reads messages
- Uses SMTP to send

**2. MTA (Mail Transfer Agent):**
- Email server (Postfix, Sendmail, Exchange)
- Routes email between servers
- Uses SMTP

**3. MDA (Mail Delivery Agent):**
- Delivers email to mailbox
- Local delivery

**4. MAA (Mail Access Agent):**
- Retrieves email (POP3, IMAP)

#### **SMTP Commands:**

**Connection:**
- `HELO/EHLO` - Identify client
- `MAIL FROM:` - Sender address
- `RCPT TO:` - Recipient address
- `DATA` - Email content follows
- `QUIT` - Close connection

**Example Session:**
```
Client: EHLO client.example.com
Server: 250 Hello client.example.com

Client: MAIL FROM:<sender@example.com>
Server: 250 OK

Client: RCPT TO:<recipient@example.com>
Server: 250 OK

Client: DATA
Server: 354 Start mail input

Client: Subject: Test Email
Client:
Client: This is the email body.
Client: .
Server: 250 OK Message accepted

Client: QUIT
Server: 221 Bye
```

#### **SMTP Response Codes:**

- **2xx:** Success
  - 220: Service ready
  - 250: Requested action completed
  - 251: User not local, will forward
- **3xx:** Need more information
  - 354: Start mail input
- **4xx:** Temporary failure
  - 450: Mailbox busy
- **5xx:** Permanent failure
  - 550: Mailbox unavailable
  - 552: Exceeded storage
  - 553: Mailbox name invalid

#### **Email Retrieval Protocols:**

**1. POP3 (Post Office Protocol v3):**
- Port 110
- Download and delete from server
- Simple
- Offline access

**2. IMAP (Internet Message Access Protocol):**
- Port 143
- Messages stay on server
- Folder management
- Multiple device sync
- More complex

#### **MIME (Multipurpose Internet Mail Extensions):**

**Purpose:** Send non-ASCII content

**Supports:**
- Attachments (images, videos, documents)
- Non-English characters
- HTML email
- Multiple parts

**Headers:**
- `MIME-Version:` Version (1.0)
- `Content-Type:` Type of content
- `Content-Transfer-Encoding:` Encoding method

**Content Types:**
- text/plain
- text/html
- image/jpeg
- application/pdf
- multipart/mixed (attachments)

#### **Email Security:**

**Problems:**
- Plaintext transmission
- Spoofing (fake sender)
- Spam
- Phishing

**Solutions:**

**1. SPF (Sender Policy Framework):**
- DNS record lists authorized senders
- Prevents spoofing

**2. DKIM (DomainKeys Identified Mail):**
- Digital signature
- Verifies sender

**3. DMARC (Domain-based Message Authentication):**
- Policy framework
- Uses SPF and DKIM

**4. TLS/SSL:**
- Encrypt connection
- STARTTLS command

---

### 6.5 SNMP (Simple Network Management Protocol)

**Purpose:** Monitor and manage network devices

**Port:**
- **161:** SNMP agent (device)
- **162:** SNMP trap (notifications)

**Protocol:** UDP (efficiency)

**Characteristics:**
- Application layer protocol
- Lightweight
- Client-server model
- Polling and event-based

#### **SNMP Architecture:**

**Components:**

**1. SNMP Manager:**
- Monitoring station
- Sends requests
- Receives traps
- Example: Network Management Software (Nagios, PRTG, SolarWinds)

**2. SNMP Agent:**
- Software on managed device
- Responds to requests
- Sends traps
- Runs on routers, switches, servers, printers

**3. MIB (Management Information Base):**
- Database of managed objects
- Hierarchical structure
- OID (Object Identifier)
- Standard and vendor-specific

**4. Managed Objects:**
- Variables representing device state
- Examples: CPU usage, interface status, temperature

#### **SNMP Operations:**

**1. GET:**
- Manager requests single object value
- Agent responds with value

**2. GET-NEXT:**
- Retrieve next object in MIB tree
- Table traversal

**3. GET-BULK:**
- Retrieve multiple objects efficiently
- SNMPv2 and later

**4. SET:**
- Manager modifies object value
- Configure device

**5. TRAP:**
- Unsolicited message from agent
- Event notification
- Example: Link down, high CPU

**6. INFORM:**
- Acknowledged trap
- Reliable notification

#### **SNMP Versions:**

**SNMPv1:**
- Original version
- Community strings (password)
- No encryption
- Security: Community-based

**SNMPv2c:**
- Improved performance
- GET-BULK operation
- Still uses community strings
- Widely used

**SNMPv3:**
- Security features
- Authentication (HMAC-MD5, HMAC-SHA)
- Encryption (DES, AES)
- User-based security
- Most secure

#### **MIB Structure:**

**OID Example:**
```
1.3.6.1.2.1.1.1.0
|  |  |  |  |  |  |
|  |  |  |  |  |  +-- Instance
|  |  |  |  |  +-- System Description
|  |  |  |  +-- System Group
|  |  |  +-- MIB-2
|  |  +-- Management
|  +-- Internet
+-- ISO-identified
```

**Common OIDs:**
- System Description: 1.3.6.1.2.1.1.1
- System Uptime: 1.3.6.1.2.1.1.3
- Interface Count: 1.3.6.1.2.1.2.1

**Use Cases:**
- Network monitoring
- Performance measurement
- Fault detection
- Configuration management
- Capacity planning

**Advantages:**
- Vendor independent
- Widely supported
- Lightweight
- Extensible (custom MIBs)

**Disadvantages:**
- UDP unreliable
- Security issues (v1, v2c)
- Complex MIB structure
- Polling overhead

---

### 6.6 HTTP (Hypertext Transfer Protocol)

**Purpose:** Transfer web pages and resources

**Port:**
- **80:** HTTP
- **443:** HTTPS (HTTP Secure)

**Protocol:** TCP

**Characteristics:**
- Application layer protocol
- Request-response model
- Stateless (each request independent)
- Text-based

#### **HTTP Architecture:**

**Client-Server Model:**
- **Client:** Web browser (Chrome, Firefox, Safari)
- **Server:** Web server (Apache, Nginx, IIS)

**HTTP Versions:**

**HTTP/1.0:**
- Non-persistent connections
- One request per connection
- Simple but inefficient

**HTTP/1.1:**
- Persistent connections (keep-alive)
- Pipelining
- Chunked transfer
- Host header (virtual hosting)
- Most widely used

**HTTP/2:**
- Binary protocol
- Multiplexing (multiple requests on one connection)
- Server push
- Header compression
- Better performance

**HTTP/3:**
- Uses QUIC instead of TCP
- Faster connection establishment
- Better mobile performance

#### **HTTP Request Format:**

```
Request Line
Headers
[Blank Line]
[Message Body]
```

**Example:**
```
GET /index.html HTTP/1.1
Host: www.example.com
User-Agent: Mozilla/5.0
Accept: text/html
Connection: keep-alive

```

**Request Line:**
- **Method:** GET, POST, PUT, DELETE, etc.
- **URI:** Resource path
- **Version:** HTTP/1.1

#### **HTTP Methods:**

**1. GET:**
- Retrieve resource
- No body
- Idempotent (safe to repeat)
- Cacheable

**2. POST:**
- Submit data
- Has body
- Not idempotent
- Create resource

**3. PUT:**
- Update resource
- Replace entire resource
- Idempotent

**4. DELETE:**
- Remove resource
- Idempotent

**5. HEAD:**
- Like GET but no body
- Check if resource exists
- Get metadata

**6. OPTIONS:**
- Query server capabilities
- CORS preflight

**7. PATCH:**
- Partial update
- Modify part of resource

#### **HTTP Response Format:**

```
Status Line
Headers
[Blank Line]
[Message Body]
```

**Example:**
```
HTTP/1.1 200 OK
Date: Mon, 08 Nov 2025 10:30:00 GMT
Server: Apache/2.4.41
Content-Type: text/html
Content-Length: 1234
Connection: keep-alive

<html>
<body>Hello World</body>
</html>
```

#### **HTTP Status Codes:**

**1xx: Informational**
- 100: Continue
- 101: Switching Protocols

**2xx: Success**
- 200: OK (success)
- 201: Created (POST success)
- 204: No Content (success, no response body)

**3xx: Redirection**
- 301: Moved Permanently
- 302: Found (temporary redirect)
- 304: Not Modified (cached version valid)

**4xx: Client Error**
- 400: Bad Request
- 401: Unauthorized (authentication required)
- 403: Forbidden (no permission)
- 404: Not Found
- 405: Method Not Allowed

**5xx: Server Error**
- 500: Internal Server Error
- 502: Bad Gateway
- 503: Service Unavailable
- 504: Gateway Timeout

#### **HTTP Headers:**

**Request Headers:**
- `Host:` Domain name (required in HTTP/1.1)
- `User-Agent:` Browser/client info
- `Accept:` Content types accepted
- `Accept-Language:` Preferred language
- `Cookie:` Session data
- `Authorization:` Credentials
- `Referer:` Previous page URL

**Response Headers:**
- `Server:` Server software
- `Content-Type:` Media type (text/html, application/json)
- `Content-Length:` Body size in bytes
- `Set-Cookie:` Store cookie
- `Cache-Control:` Caching directives
- `Location:` Redirect URL

**General Headers:**
- `Connection:` keep-alive or close
- `Date:` Message date/time

#### **Cookies:**

**Purpose:** Maintain state in stateless HTTP

**How it works:**
1. Server sends `Set-Cookie` header
2. Browser stores cookie
3. Browser sends cookie with future requests
4. Server identifies user/session

**Cookie Attributes:**
- **Domain:** Which domain can access
- **Path:** Which paths can access
- **Expires:** Expiration date
- **Secure:** Only send over HTTPS
- **HttpOnly:** No JavaScript access (XSS protection)

**Use Cases:**
- Session management
- User preferences
- Tracking and analytics
- Shopping cart

#### **HTTPS (HTTP Secure):**

**Purpose:** Secure HTTP with encryption

**Characteristics:**
- Uses TLS/SSL
- Encrypts entire communication
- Port 443
- Certificate-based authentication

**How it works:**
1. Client initiates connection
2. Server sends SSL certificate
3. Client verifies certificate
4. Key exchange using asymmetric encryption
5. Symmetric encryption for data transfer

**Benefits:**
- Data confidentiality
- Data integrity
- Server authentication
- SEO ranking boost
- User trust

**Certificate Authorities (CA):**
- Issue SSL certificates
- Examples: Let's Encrypt, DigiCert, Comodo
- Browser trusts CA root certificates

---

## ADDITIONAL IMPORTANT TOPICS

### Network Devices Deep Dive

#### **Router Bridge Function:**

**Bridge:**
- Operates at Layer 2
- Forwards based on MAC address
- Connects same type of networks
- Two ports typically
- Learns MAC addresses

**Router:**
- Operates at Layer 3
- Forwards based on IP address
- Connects different networks
- Multiple interfaces
- Routing table based

**Router-Bridge (Brouter):**
- Can function as both
- Routes routable protocols
- Bridges non-routable protocols

---

### DNS (Domain Name System)

**Purpose:** Translate domain names to IP addresses

**Port:** 53 (UDP for queries, TCP for zone transfers)

**Why DNS:**
- Humans remember names better than numbers
- www.example.com → 192.0.2.1

**DNS Hierarchy:**

```
                     Root (.)
                    /    |    \
                  /      |      \
               com      org      net     (TLDs)
              /         |          \
          google    wikipedia     example
           /            |             \
        www           www            ftp
```

**DNS Components:**

**1. DNS Resolver (Client):**
- Initiates queries
- Usually in OS

**2. DNS Server Types:**

**a) Recursive Resolver:**
- Queries on behalf of client
- Caches responses
- Usually ISP DNS

**b) Root Name Server:**
- 13 root servers worldwide (A-M)
- Knows TLD servers
- Top of hierarchy

**c) TLD Name Server:**
- Manages top-level domains (.com, .org, .in)
- Knows authoritative servers

**d) Authoritative Name Server:**
- Has actual DNS records
- Final answer for domain

**DNS Query Process:**

```
1. User types www.example.com in browser
2. Browser checks local DNS cache
3. If not found, asks OS resolver
4. Resolver asks Recursive DNS server (ISP)
5. Recursive server checks cache
6. If not cached:
   a) Asks Root server: "Where is .com?"
   b) Root responds with TLD server address
   c) Asks TLD server: "Where is example.com?"
   d) TLD responds with Authoritative server
   e) Asks Authoritative: "What is www.example.com?"
   f) Authoritative responds with IP address
7. Recursive server caches and returns to client
8. Browser connects to IP address
```

**DNS Record Types:**

**1. A Record:**
- Maps domain to IPv4 address
- Example: example.com → 192.0.2.1

**2. AAAA Record:**
- Maps domain to IPv6 address
- Example: example.com → 2001:db8::1

**3. CNAME (Canonical Name):**
- Alias to another domain
- Example: www.example.com → example.com

**4. MX (Mail Exchange):**
- Mail server for domain
- Has priority number
- Example: example.com → mail.example.com (priority 10)

**5. NS (Name Server):**
- Authoritative name servers for domain
- Example: example.com → ns1.example.com

**6. PTR (Pointer):**
- Reverse DNS lookup
- IP to domain name
- Used for email validation

**7. TXT (Text):**
- Arbitrary text data
- SPF records, domain verification
- Example: "v=spf1 include:_spf.google.com ~all"

**8. SOA (Start of Authority):**
- Administrative information
- Primary name server, admin email, serial number

**DNS Caching:**
- TTL (Time To Live) determines cache duration
- Reduces DNS query load
- Faster responses
- Multiple cache levels (browser, OS, resolver)

**DNS Security:**

**1. DNS Spoofing/Cache Poisoning:**
- Attacker injects false DNS data
- Redirects users to malicious sites

**2. DNSSEC (DNS Security Extensions):**
- Adds digital signatures
- Verifies authenticity
- Prevents tampering

---

### TCP (Transmission Control Protocol) - Additional Details

#### **TCP States:**

**Connection States:**

1. **CLOSED:** No connection
2. **LISTEN:** Server waiting for connection
3. **SYN_SENT:** Client sent SYN, waiting for SYN-ACK
4. **SYN_RECEIVED:** Server received SYN, sent SYN-ACK
5. **ESTABLISHED:** Connection established, data transfer
6. **FIN_WAIT_1:** Sent FIN, waiting for ACK
7. **FIN_WAIT_2:** Received ACK, waiting for FIN
8. **CLOSE_WAIT:** Received FIN, waiting to close
9. **CLOSING:** Both sides closing simultaneously
10. **LAST_ACK:** Sent FIN, waiting for ACK
11. **TIME_WAIT:** Waiting for network to clear
12. **CLOSED:** Connection terminated

**State Transition Diagram:**
```
Client                    Server
------                    ------
CLOSED                    CLOSED
  |                         |
  | (active open)          | (passive open)
  v                         v
SYN_SENT  --SYN-->      LISTEN
  |                         |
  |     <--SYN-ACK--    SYN_RECEIVED
  v                         |
ESTABLISHED  --ACK-->   ESTABLISHED
  |                         |
(data transfer)       (data transfer)
  |                         |
FIN_WAIT_1  --FIN-->    CLOSE_WAIT
  |                         |
  |     <--ACK--            |
  v                         |
FIN_WAIT_2                  |
  |                         |
  |     <--FIN--            |
  v                         v
TIME_WAIT  --ACK-->     LAST_ACK
  |                         |
  | (2MSL timeout)      (ACK received)
  v                         v
CLOSED                    CLOSED
```

#### **TCP Timers:**

**1. Retransmission Timer:**
- Starts when segment sent
- Fires if no ACK received
- RTO (Retransmission Timeout) dynamically calculated

**2. Persistent Timer:**
- Used with zero window
- Prevents deadlock
- Sends probe segments

**3. Keep-alive Timer:**
- Checks if connection still alive
- Sends probe after idle period
- Default: 2 hours

**4. TIME_WAIT Timer:**
- 2MSL (Maximum Segment Lifetime)
- Ensures old segments expire
- Typically 1-4 minutes

#### **TCP Congestion Control Algorithms:**

**1. Slow Start:**
- Begin with cwnd = 1 MSS
- Exponential growth
- Double each RTT
- Continue until threshold

**2. Congestion Avoidance:**
- Linear growth
- Increment by 1 MSS per RTT
- Additive increase

**3. Fast Retransmit:**
- 3 duplicate ACKs
- Immediate retransmission
- Don't wait for timeout

**4. Fast Recovery:**
- After fast retransmit
- Skip slow start
- Set cwnd = threshold
- Continue with congestion avoidance

**Congestion Window Evolution:**
```
cwnd
  |     Slow Start    | Congestion Avoidance |
  |                   |                      |
  |        /|         |      ___             |
  |       / |         |     /   \___         |
  |      /  |         |    /        \___     |
  |     /   |         |   /             \    |
  |    /    |         |  /               \   |
  |___/_____|_________|_/________________ \___|
          threshold   timeout          time
```

---

### MAC Layer (Media Access Control)

**MAC Address:**
- 48-bit physical address
- Burned into NIC (Network Interface Card)
- Hexadecimal format: AA:BB:CC:DD:EE:FF
- First 24 bits: OUI (Organizationally Unique Identifier) - vendor
- Last 24 bits: Device identifier

**MAC Address Types:**

**1. Unicast:**
- Single destination
- First byte LSB = 0
- Example: 00:1A:2B:3C:4D:5E

**2. Multicast:**
- Group of devices
- First byte LSB = 1
- Example: 01:00:5E:xx:xx:xx (IPv4 multicast)

**3. Broadcast:**
- All devices
- FF:FF:FF:FF:FF:FF

**Special MAC Addresses:**
- 00:00:00:00:00:00 - Invalid/not set
- FF:FF:FF:FF:FF:FF - Broadcast
- 01:00:5E:00:00:00 to 01:00:5E:7F:FF:FF - IPv4 multicast

**ARP (Address Resolution Protocol):**

**Purpose:** Map IP address to MAC address

**Working:**
1. Host A wants to send to Host B (knows IP, needs MAC)
2. Host A checks ARP cache
3. If not found, broadcasts ARP request:
   - "Who has IP 192.168.1.10? Tell 192.168.1.5"
4. All hosts receive broadcast
5. Host B recognizes its IP, sends ARP reply (unicast):
   - "192.168.1.10 is at AA:BB:CC:DD:EE:FF"
6. Host A updates ARP cache
7. Host A can now send to Host B

**ARP Cache:**
- Temporary mapping table
- Entries expire (typically 2-20 minutes)
- Command: `arp -a` (view cache)

**RARP (Reverse ARP):**
- Maps MAC to IP
- Used by diskless workstations
- Largely replaced by DHCP

---

### DHCP (Dynamic Host Configuration Protocol)

**Purpose:** Automatically assign IP addresses

**Port:** 67 (server), 68 (client)

**Protocol:** UDP

**Why DHCP:**
- Eliminates manual IP configuration
- Prevents IP conflicts
- Centralizes management
- Supports mobile devices

**DHCP Message Types:**

**1. DHCPDISCOVER:**
- Client broadcasts to find DHCP server
- Destination: 255.255.255.255

**2. DHCPOFFER:**
- Server offers IP address
- Includes lease time, subnet mask, gateway

**3. DHCPREQUEST:**
- Client requests offered IP
- Broadcasted (multiple servers may have offered)

**4. DHCPACK:**
- Server acknowledges
- Client configures network

**DHCP Process (DORA):**

```
Client                          DHCP Server
  |                                  |
  |------ DHCPDISCOVER (broadcast)---|-> Discover
  |                                  |
  |<----- DHCPOFFER (unicast) -------|   Offer
  |                                  |
  |------ DHCPREQUEST (broadcast)----|-> Request
  |                                  |
  |<----- DHCPACK (unicast) ---------|   Acknowledge
  |                                  |
(Client configured)
```

**DHCP Lease:**
- Temporary IP assignment
- Lease time (hours/days)
- Renewal at 50% of lease time
- Rebinding at 87.5% if renewal fails

**DHCP Scope:**
- Range of IP addresses to assign
- Example: 192.168.1.100 - 192.168.1.200
- Excludes static IPs

**Information Provided by DHCP:**
- IP address
- Subnet mask
- Default gateway
- DNS servers
- Domain name
- Lease duration
- WINS servers (Windows)

**DHCP Relay Agent:**
- Forwards DHCP messages across subnets
- Broadcasts don't cross routers
- Relay agent forwards to DHCP server

---

### Network Congestion - Additional Details

**Types of Congestion:**

**1. Send-side Congestion:**
- Sender transmits too fast
- Network cannot handle

**2. Receive-side Congestion:**
- Receiver cannot process fast enough
- Buffer overflow

**3. Network Congestion:**
- Too many packets in network
- Router buffers full

**Congestion Indicators:**
- Packet loss
- Increased delay
- Timeout
- Decreased goodput

**Leaky Bucket Algorithm:**

**Concept:** Regulate traffic flow

**Working:**
- Bucket with fixed capacity
- Water (packets) enters at variable rate
- Leaks out at constant rate
- If bucket full, excess water spills (packets dropped)

**Characteristics:**
- Output rate constant
- Smooths bursty traffic
- Simple implementation

**Token Bucket Algorithm:**

**Concept:** Allow controlled bursts

**Working:**
- Tokens generated at constant rate
- Stored in bucket (max capacity)
- Packet needs token to transmit
- If no token, packet waits or dropped
- Allows bursts up to bucket size

**Characteristics:**
- More flexible than leaky bucket
- Allows bursts
- Better for variable traffic

**Comparison:**
- Leaky: Constant output, no bursts
- Token: Variable output, allows bursts

---

### ISDN (Integrated Services Digital Network)

**Purpose:** Digital telephone network for voice, video, data

**Developed:** 1980s

**Characteristics:**
- Circuit-switched
- Digital end-to-end
- Multiple services on same line

**ISDN Channels:**

**B Channel (Bearer):**
- 64 Kbps
- Carries user data (voice, video, data)

**D Channel (Delta/Data):**
- 16 or 64 Kbps
- Signaling and control
- Can carry low-speed data

**ISDN Types:**

**1. BRI (Basic Rate Interface):**
- 2B + D
- 2 × 64 Kbps (B) + 16 Kbps (D)
- Total: 144 Kbps
- Home and small business

**2. PRI (Primary Rate Interface):**
- **North America/Japan:** 23B + D
  - 23 × 64 Kbps + 64 Kbps = 1.544 Mbps (T1)
- **Europe:** 30B + D
  - 30 × 64 Kbps + 64 Kbps = 2.048 Mbps (E1)
- Large organizations

**ISDN Layers:**

**Layer 1 (Physical):**
- BRI: U-interface, S/T interface
- PRI: T1/E1 interface

**Layer 2 (Data Link):**
- LAPD (Link Access Procedure, D-channel)
- Similar to HDLC

**Layer 3 (Network):**
- Q.931 protocol
- Call setup, maintenance, teardown

**ISDN Applications:**
- Video conferencing
- High-speed internet (pre-DSL era)
- Remote access
- Backup for leased lines

**Advantages:**
- Digital quality
- Fast call setup
- Multiple services
- Error-free transmission

**Disadvantages:**
- Expensive installation
- Replaced by DSL and fiber
- Limited bandwidth by modern standards

---

### Multimedia Elements

**Multimedia:** Combination of multiple content forms

**Elements:**

**1. Text:**
- Alphanumeric characters
- Smallest storage
- Easy to transmit
- Formats: TXT, RTF, DOC, PDF

**2. Graphics/Images:**
- Still pictures
- Raster (bitmap) or Vector
- **Formats:**
  - JPEG: Compressed photos
  - PNG: Lossless, transparency
  - GIF: Animation, limited colors
  - BMP: Uncompressed
  - SVG: Vector graphics

**3. Audio:**
- Sound, music, voice
- Analog → Digital (sampling)
- **Parameters:**
  - Sample rate (44.1 kHz for CD)
  - Bit depth (16-bit, 24-bit)
- **Formats:**
  - MP3: Compressed, lossy
  - WAV: Uncompressed
  - AAC: Better than MP3
  - FLAC: Lossless compression

**4. Video:**
- Moving pictures with audio
- Sequence of frames
- **Parameters:**
  - Frame rate (24, 30, 60 fps)
  - Resolution (1080p, 4K)
  - Bitrate
- **Formats:**
  - MP4: Most common
  - AVI: Windows standard
  - MKV: High quality
  - WebM: Web streaming
- **Codecs:** H.264, H.265, VP9

**5. Animation:**
- Simulated motion graphics
- 2D or 3D
- Formats: GIF, SVG, Flash (deprecated)

**6. Interactivity:**
- User input and control
- Buttons, links, forms
- Applications, games

**Multimedia Characteristics:**
- Large file sizes
- High bandwidth requirements
- Real-time transmission needs
- Synchronization (audio-video)
- Quality of Service (QoS) important

**Multimedia Applications:**
- Video conferencing
- Online gaming
- Streaming services (Netflix, YouTube)
- E-learning
- Virtual reality
- Video calls (Zoom, Teams)

**Multimedia Compression:**

**Why Compress:**
- Reduce storage
- Faster transmission
- Lower bandwidth

**Types:**
- **Lossy:** Loses some quality (JPEG, MP3)
- **Lossless:** No quality loss (PNG, FLAC)

---

### LAN, WAN, MAN - Detailed Comparison

**Protocols Used:**

**LAN Protocols:**
- **Ethernet (IEEE 802.3):**
  - Most common
  - Speeds: 10 Mbps to 100 Gbps
  - CSMA/CD (wired)

- **Wi-Fi (IEEE 802.11):**
  - Wireless LAN
  - Standards: 802.11a/b/g/n/ac/ax (Wi-Fi 6)
  - 2.4 GHz and 5 GHz bands
  - CSMA/CA

- **Token Ring (IEEE 802.5):**
  - Obsolete
  - 4 or 16 Mbps
  - Token passing

- **FDDI (Fiber Distributed Data Interface):**
  - 100 Mbps over fiber
  - Dual ring topology
  - Campus backbone

**MAN Protocols:**
- **Metro Ethernet:**
  - Ethernet extended to metro area
  - Service provider networks

- **SONET/SDH:**
  - Synchronous Optical Network
  - High-speed fiber

- **DOCSIS:**
  - Cable modem standard
  - Data over cable TV

- **WiMAX (IEEE 802.16):**
  - Wireless MAN
  - Long range (50 km)
  - Replaced by LTE

**WAN Protocols:**
- **PPP (Point-to-Point Protocol):**
  - Serial connections
  - Dial-up, DSL

- **HDLC (High-Level Data Link Control):**
  - Cisco default for serial links

- **Frame Relay:**
  - Packet switching
  - Virtual circuits
  - Legacy (mostly replaced)

- **ATM (Asynchronous Transfer Mode):**
  - Cell switching (53-byte cells)
  - QoS support
  - Largely replaced

- **MPLS (Multiprotocol Label Switching):**
  - Modern WAN protocol
  - Label-based routing
  - Traffic engineering
  - VPN support

- **Leased Lines:**
  - T1/E1: 1.544/2.048 Mbps
  - T3/E3: 45/34 Mbps
  - OC-3/STM-1: 155 Mbps

**Network Comparison Table:**

| Feature | LAN | MAN | WAN |
|---------|-----|-----|-----|
| **Coverage** | Building/Campus | City | Country/World |
| **Range** | Up to 1 km | 10-100 km | Unlimited |
| **Speed** | 10 Mbps - 100 Gbps | 10 Mbps - 100 Gbps | 56 Kbps - 100 Gbps |
| **Ownership** | Private | Public/Private | Public/Multiple |
| **Technology** | Ethernet, Wi-Fi | Metro Ethernet, SONET | MPLS, Leased Lines |
| **Error Rate** | Low | Medium | Higher |
| **Latency** | Very Low (<1 ms) | Low (5-10 ms) | Higher (>50 ms) |
| **Cost** | Low | Medium | High |
| **Maintenance** | Easy | Moderate | Complex |
| **Example** | Office network | City cable network | Internet |

---

### Hubs vs Switches - Detailed Comparison

**Hub (Layer 1 Device):**

**Characteristics:**
- Physical layer device
- Multi-port repeater
- Broadcasts to all ports
- No intelligence
- Half-duplex
- Single collision domain
- Single broadcast domain

**Types:**
- **Passive Hub:** No signal regeneration
- **Active Hub:** Regenerates signals
- **Intelligent Hub:** Management features

**Working:**
1. Receives signal on one port
2. Regenerates signal
3. Broadcasts to ALL other ports
4. All devices receive, only intended recipient processes

**Disadvantages:**
- Wastes bandwidth
- Security risk (all see all data)
- Collisions
- Performance degrades with load

**When to Use:**
- Very small networks
- Cost extremely sensitive
- Simple monitoring/sniffing needed

---

**Switch (Layer 2 Device):**

**Characteristics:**
- Data link layer device
- Intelligent forwarding
- MAC address table
- Each port = collision domain
- Still one broadcast domain (per VLAN)
- Full-duplex capable
- Faster than hub

**Working:**
1. Receives frame
2. Reads destination MAC
3. Looks up in MAC table
4. Forwards ONLY to destination port
5. If MAC unknown, floods all ports

**MAC Address Table:**
```
MAC Address         Port    Age
00:1A:2B:3C:4D:5E   1       30 sec
00:1A:2B:3C:4D:5F   2       25 sec
00:1A:2B:3C:4D:60   3       10 sec
```

**Learning Process:**
- Initially table empty
- Learns from source MAC of received frames
- Dynamic entries age out
- Static entries can be configured

**Switch Types:**

**1. Unmanaged Switch:**
- Plug and play
- No configuration
- Fixed settings
- Home/small office

**2. Managed Switch:**
- Configurable
- VLANs, QoS, port mirroring
- SNMP management
- Command-line interface
- Enterprise use

**3. Smart/Web-Managed Switch:**
- Basic management features
- Web interface
- Between unmanaged and managed

**Switching Methods:**

**1. Store-and-Forward:**
- Receives entire frame
- Checks CRC
- Then forwards
- Slower but reliable
- Error checking

**2. Cut-Through:**
- Starts forwarding after destination MAC
- Reads first 6 bytes, forwards immediately
- Faster but no error checking
- Forwards bad frames too

**3. Fragment-Free:**
- Hybrid approach
- Reads first 64 bytes (collision window)
- Checks for collisions
- Then forwards
- Balance of speed and reliability

**Switch Features:**

**1. VLAN (Virtual LAN):**
- Logical segmentation
- Separate broadcast domains
- Security isolation
- Example: Finance VLAN, HR VLAN

**2. Spanning Tree Protocol (STP):**
- Prevents loops
- Blocks redundant paths
- Enables redundancy

**3. Port Mirroring/SPAN:**
- Copy traffic to monitoring port
- Network analysis

**4. QoS (Quality of Service):**
- Prioritize traffic
- Voice/video higher priority

**5. PoE (Power over Ethernet):**
- Deliver power over data cable
- IP phones, cameras, APs

**6. Link Aggregation:**
- Combine multiple ports
- Increased bandwidth and redundancy

**Comparison Summary:**

| Feature | Hub | Switch |
|---------|-----|--------|
| Layer | Physical (1) | Data Link (2) |
| Intelligence | None | MAC learning |
| Forwarding | Broadcast | Selective |
| Collision Domain | One | Per port |
| Duplex | Half only | Full capable |
| Speed | Shared | Dedicated per port |
| Security | Low | Better |
| Performance | Poor | Good |
| Cost | Very cheap | Moderate |
| Use | Obsolete | Standard today |

---

### Baseband vs Broadband Communication

**Baseband Communication:**

**Definition:** Digital signal transmitted directly on medium without modulation

**Characteristics:**
- Single channel
- Digital signals
- Entire bandwidth for one signal
- Bidirectional but not simultaneous
- Short distance
- Simple, low cost

**Examples:**
- Ethernet (10Base-T, 100Base-TX)
- USB
- Serial cables

**Advantages:**
- Simple technology
- Low cost
- No modulation needed
- Easy installation

**Disadvantages:**
- Limited distance
- Single channel
- Attenuation issues

**Encoding Schemes:**
- Manchester encoding (Ethernet)
- Differential Manchester
- 4B/5B encoding

---

**Broadband Communication:**

**Definition:** Analog signaling using modulation, multiple channels on same medium

**Characteristics:**
- Multiple channels (FDM)
- Analog signals
- Wide frequency band divided
- Unidirectional (need two paths for bidirectional)
- Long distance
- Complex, higher cost

**Examples:**
- Cable TV
- Cable internet (DOCSIS)
- DSL
- Cellular networks (3G, 4G, 5G)

**Advantages:**
- Multiple channels
- Long distance
- Higher capacity
- Multiplexing support

**Disadvantages:**
- Expensive
- Complex equipment
- Amplifiers needed
- Installation complex

**Modulation Techniques:**
- **AM (Amplitude Modulation)**
- **FM (Frequency Modulation)**
- **PM (Phase Modulation)**
- **QAM (Quadrature Amplitude Modulation)**

**Frequency Division Multiplexing (FDM):**
- Divide bandwidth into channels
- Each channel for different signal
- Guard bands prevent interference

**Example: Cable TV**
```
Frequency Spectrum:
|--- Channel 2 ---|--- Channel 3 ---|--- Channel 4 ---|
| 54-60 MHz      | 60-66 MHz      | 66-72 MHz      |
```

**Comparison:**

| Feature | Baseband | Broadband |
|---------|----------|-----------|
| Signal | Digital | Analog |
| Channels | Single | Multiple |
| Distance | Short | Long |
| Direction | Bidirectional | Unidirectional |
| Modulation | No | Yes |
| Cost | Low | High |
| Complexity | Simple | Complex |
| Bandwidth Usage | Full | Divided |
| Example | Ethernet | Cable TV |

---

### Socket Programming Concepts

**Socket:**
- Endpoint for network communication
- Interface between application and transport layer
- Identified by (IP address, Port number, Protocol)

**Types of Sockets:**

**1. Stream Socket (SOCK_STREAM):**
- Uses TCP
- Connection-oriented
- Reliable, ordered delivery
- Example: Web browsers, file transfer

**2. Datagram Socket (SOCK_DGRAM):**
- Uses UDP
- Connectionless
- Unreliable, unordered
- Example: DNS, video streaming

**3. Raw Socket:**
- Direct access to IP layer
- Bypass transport layer
- Requires privileges
- Example: Ping, traceroute

**Socket States:**

**Active Socket:**
- Client socket
- Initiates connection
- Calls connect()

**Passive Socket:**
- Server socket
- Listens for connections
- Calls listen() and accept()

**TCP Socket Communication:**

**Server Side:**
```
1. socket() - Create socket
2. bind() - Bind to address and port
3. listen() - Mark as passive, set queue size
4. accept() - Wait for client connection
5. recv()/send() - Receive and send data
6. close() - Close socket
```

**Client Side:**
```
1. socket() - Create socket
2. connect() - Connect to server
3. send()/recv() - Send and receive data
4. close() - Close socket
```

**UDP Socket Communication:**

**Server:**
```
1. socket() - Create socket
2. bind() - Bind to address and port
3. recvfrom() - Receive data with sender info
4. sendto() - Send data to specific address
5. close() - Close socket
```

**Client:**
```
1. socket() - Create socket
2. sendto() - Send data to server
3. recvfrom() - Receive response
4. close() - Close socket
```

**Difference Between Active and Passive:**

| Active Socket | Passive Socket |
|---------------|----------------|
| Client-side | Server-side |
| Initiates connection | Waits for connection |
| Uses connect() | Uses listen() and accept() |
| One connection | Multiple connections |
| Short-lived | Long-lived |

---

### Star vs Ring Topology - Detailed Comparison with Diagrams

**Star Topology:**

**Diagram:**
```
        Device C
            |
            |
    Device B --- HUB/SWITCH --- Device D
            |
            |
        Device A
```

**Characteristics:**
- Central node (hub/switch)
- All devices connect to center
- Hub/switch manages communication
- Most common today

**Data Flow:**
- Device A → Central node → Device B
- Central node acts as repeater/switch

**Advantages:**
- Easy to install and configure
- Adding/removing devices is simple
- Failure of one device doesn't affect others
- Easy troubleshooting (centralized)
- Better performance than bus
- Different data rates on different ports

**Disadvantages:**
- Central node failure = total failure
- Requires more cable than bus
- Hub/switch cost
- Limited by central node capacity

**Applications:**
- Modern LANs
- Home networks
- Office networks
- School computer labs

**Variations:**
- **Extended Star:** Multiple stars connected
- **Distributed Star:** Hierarchical star

---

**Ring Topology:**

**Diagram:**
```
    Device A -------- Device B
        |                 |
        |                 |
    Device D -------- Device C

    (Data flows in one direction)
```

**Characteristics:**
- Devices connected in closed loop
- Each device has exactly two neighbors
- Data travels in one direction (or both in dual ring)
- No central node

**Data Flow:**
- Token passing mechanism
- Device holds token can transmit
- Data packet travels around ring
- Destination copies data
- Packet continues to sender
- Sender removes packet

**Token Ring Operation:**
1. Free token circulates when idle
2. Device wanting to send captures token
3. Converts to data frame
4. Sends data
5. Data circulates ring
6. Destination copies data
7. Frame returns to sender
8. Sender verifies delivery
9. Releases free token

**Advantages:**
- No collision (token prevents)
- Equal access for all devices
- Predictable performance
- Can handle heavy load better than bus
- All devices act as repeaters

**Disadvantages:**
- Single device/cable failure breaks ring
- Difficult to add/remove devices
- Troubleshooting difficult
- Slower than star for small networks
- Entire network down during reconfiguration

**Ring Topology Types:**

**1. Single Ring:**
- One ring
- Unidirectional flow
- If break occurs, network fails

**2. Dual Ring (FDDI):**
- Two counter-rotating rings
- Primary and secondary
- If primary fails, secondary takes over
- Higher reliability

**Applications:**
- Token Ring networks (IBM, obsolete)
- FDDI (campus backbones, largely replaced)
- SONET/SDH (optical networks)

**Comparison Table:**

| Feature | Star | Ring |
|---------|------|------|
| Central Node | Yes (hub/switch) | No |
| Failure Impact | Only failed device | Entire network |
| Cable Required | More | Less |
| Installation | Easy | Moderate |
| Reconfiguration | Easy | Difficult |
| Collision | Possible (hub) | No (token) |
| Cost | Moderate-High | Moderate |
| Performance | Good | Predictable |
| Scalability | Good | Limited |
| Troubleshooting | Easy | Difficult |
| Current Use | Very common | Rare (obsolete) |

---

### Important Interview Questions & Answers

**Q1: What happens when you type google.com in browser?**

**Answer:**
1. **Browser cache check:** Browser checks if IP address is cached
2. **OS cache check:** If not, OS checks its DNS cache
3. **Router cache:** Router may have cached DNS entry
4. **ISP DNS:** ISP's recursive DNS server is queried
5. **DNS Resolution:**
   - Root server queried for .com TLD server
   - TLD server queried for google.com authoritative server
   - Authoritative server returns IP address
6. **TCP Connection:** Browser initiates TCP 3-way handshake with server
7. **HTTP Request:** Browser sends HTTP GET request
8. **Server Processing:** Google's server processes request
9. **HTTP Response:** Server sends HTML, CSS, JavaScript
10. **Rendering:** Browser renders the webpage
11. **Additional Requests:** Browser requests images, CSS, JS files
12. **Page Display:** Complete page is displayed to user

---

**Q2: Difference between Hub, Switch, and Router?**

**Answer:**

| Device | Layer | Function | Intelligence |
|--------|-------|----------|--------------|
| Hub | 1 (Physical) | Broadcasts to all ports | None |
| Switch | 2 (Data Link) | Forwards based on MAC | MAC learning |
| Router | 3 (Network) | Routes based on IP | Routing table |

- **Hub:** Simple repeater, all devices share bandwidth, one collision domain
- **Switch:** Smart forwarding, dedicated bandwidth per port, each port is collision domain
- **Router:** Connects different networks, logical addressing, separates broadcast domains

---

**Q3: What is the difference between TCP and UDP?**

**Answer:**

**TCP:**
- Connection-oriented (3-way handshake)
- Reliable (acknowledgments, retransmissions)
- Ordered delivery
- Flow control and congestion control
- Header: 20-60 bytes
- Use: HTTP, FTP, Email, SSH

**UDP:**
- Connectionless
- Unreliable (no ACK, no retransmission)
- No ordering guarantee
- No flow/congestion control
- Header: 8 bytes
- Use: DNS, DHCP, streaming, gaming

**When to use UDP:** Speed is critical, some data loss acceptable, real-time applications

---

**Q4: Explain the OSI model layers with real-world example.**

**Answer:**

Think of sending a letter:

1. **Application Layer:** Writing the letter content (what you want to say)
2. **Presentation Layer:** Choosing language, formatting (English, Hindi)
3. **Session Layer:** Starting and ending the conversation (Dear Sir... Yours faithfully)
4. **Transport Layer:** Ensuring reliable delivery (registered post vs regular)
5. **Network Layer:** Address on envelope (destination address, routing)
6. **Data Link Layer:** Postal worker handling within city (local delivery)
7. **Physical Layer:** Physical transportation (truck, plane)

**Technical Example - Email:**
1. **Application:** Email client (Gmail)
2. **Presentation:** Encryption (TLS), format conversion
3. **Session:** SMTP session establishment
4. **Transport:** TCP ensures all packets arrive
5. **Network:** IP routing across internet
6. **Data Link:** Ethernet frames on local network
7. **Physical:** Electrical signals on cable

---

**Q5: What is subnetting and why is it needed?**

**Answer:**

**Subnetting:** Dividing a large network into smaller sub-networks

**Why Needed:**
1. **Better IP utilization:** Don't waste IPs
2. **Security:** Isolate departments
3. **Performance:** Reduce broadcast traffic
4. **Management:** Easier to manage small networks
5. **Organization:** Logical grouping

**Example:**
Company has 192.168.1.0/24 (254 hosts)
- Sales: 50 users → 192.168.1.0/26 (62 hosts)
- HR: 30 users → 192.168.1.64/27 (30 hosts)
- IT: 20 users → 192.168.1.96/27 (30 hosts)

**Benefits:**
- Each department isolated
- Reduced broadcast domain
- Better security
- Efficient IP usage

---

**Q6: What is the difference between IPv4 and IPv6?**

**Answer:**

| Feature | IPv4 | IPv6 |
|---------|------|------|
| **Address Size** | 32-bit | 128-bit |
| **Address Format** | Dotted decimal (192.168.1.1) | Hexadecimal (2001:0db8::1) |
| **Total Addresses** | 4.3 billion | 340 undecillion |
| **Header Size** | 20-60 bytes | 40 bytes (fixed) |
| **Checksum** | Yes | No (done at other layers) |
| **Fragmentation** | Router and sender | Sender only |
| **Broadcast** | Yes | No (uses multicast) |
| **Configuration** | Manual or DHCP | SLAAC or DHCPv6 |
| **Security** | Optional (IPsec) | Built-in (IPsec mandatory) |
| **NAT** | Required | Not needed |
| **Example** | 192.168.1.1 | 2001:0db8:85a3::8a2e:0370:7334 |

**Why IPv6:**
- IPv4 address exhaustion
- More addresses than atoms on earth
- Better security
- Simpler header
- No NAT needed
- Auto-configuration

---

**Q7: Explain the 3-way handshake in TCP.**

**Answer:**

**Purpose:** Establish connection and synchronize sequence numbers

**Steps:**

1. **Client → Server: SYN**
   - Client sends SYN packet
   - Sequence number = X (random)
   - Client state: SYN_SENT

2. **Server → Client: SYN-ACK**
   - Server sends SYN-ACK packet
   - Sequence number = Y (random)
   - Acknowledgment = X + 1
   - Server state: SYN_RECEIVED

3. **Client → Server: ACK**
   - Client sends ACK packet
   - Acknowledgment = Y + 1
   - Connection ESTABLISHED

**Why 3 steps (not 2):**
- Prevents old duplicate connection requests
- Both sides agree on initial sequence numbers
- Confirms both sides ready to communicate

**Analogy:**
- Client: "Hello, can we talk?" (SYN)
- Server: "Yes, I'm ready to talk too" (SYN-ACK)
- Client: "Great, let's start" (ACK)

---

**Q8: What is DNS and how does it work?**

**Answer:**

**DNS (Domain Name System):** Translates domain names to IP addresses

**Example:** www.google.com → 142.250.185.46

**DNS Resolution Process:**

1. **User types:** www.example.com
2. **Browser cache:** Checks if IP cached
3. **OS cache:** Checks local DNS cache
4. **Recursive DNS (ISP):** Asks ISP's DNS server
5. **Root Server:** "Ask .com TLD server"
6. **TLD Server:** "Ask example.com authoritative server"
7. **Authoritative Server:** Returns IP address
8. **Cache and Return:** IP cached and returned to browser
9. **Browser connects** to IP address

**DNS Record Types:**
- **A Record:** Domain → IPv4
- **AAAA Record:** Domain → IPv6
- **CNAME:** Alias (www → root domain)
- **MX:** Mail server
- **NS:** Name server
- **TXT:** Text data (SPF, verification)

---

**Q9: What is ARP and how does it work?**

**Answer:**

**ARP (Address Resolution Protocol):** Maps IP address to MAC address

**Scenario:** Computer A (192.168.1.5) wants to send data to Computer B (192.168.1.10)

**Process:**

1. **Check ARP Cache:** A checks if B's MAC is in cache
2. **ARP Request (Broadcast):**
   - A sends broadcast: "Who has 192.168.1.10? Tell 192.168.1.5"
   - Destination MAC: FF:FF:FF:FF:FF:FF
3. **All Receive:** All devices on network receive broadcast
4. **B Responds (Unicast):**
   - B recognizes its IP
   - B sends: "192.168.1.10 is at AA:BB:CC:DD:EE:FF"
   - Unicast to A only
5. **Cache Update:** A updates ARP cache
6. **Communication:** A can now send frames to B using MAC

**ARP Cache Example:**
```
IP Address        MAC Address           Age
192.168.1.10      AA:BB:CC:DD:EE:FF    30 sec
192.168.1.1       11:22:33:44:55:66    120 sec
```

**Command:** `arp -a` (view ARP cache)

---

**Q10: What is NAT and why is it used?**

**Answer:**

**NAT (Network Address Translation):** Translates private IP to public IP

**Why NAT:**
1. **IPv4 shortage:** Limited public IPs available
2. **Security:** Hide internal network structure
3. **Cost:** One public IP for many devices
4. **Flexibility:** Change internal IPs without affecting external

**Types:**

**1. Static NAT:** One-to-one mapping
- Private 192.168.1.10 ↔ Public 203.0.113.10

**2. Dynamic NAT:** Many-to-many mapping
- Pool of public IPs assigned dynamically

**3. PAT (Port Address Translation) / NAPT:**
- Many-to-one mapping using ports
- Most common (home routers)

**PAT Example:**
```
Internal:
- 192.168.1.10:5000 → Web server
- 192.168.1.20:6000 → Web server

NAT Router translates to:
- 203.0.113.1:10000 → 192.168.1.10:5000
- 203.0.113.1:10001 → 192.168.1.20:6000

External sees only: 203.0.113.1
```

**NAT Table:**
| Internal IP:Port | External IP:Port | Destination |
|------------------|------------------|-------------|
| 192.168.1.10:5000 | 203.0.113.1:10000 | 8.8.8.8:80 |
| 192.168.1.20:6000 | 203.0.113.1:10001 | 1.1.1.1:443 |

**Advantages:**
- IP address conservation
- Security (internal IPs hidden)
- Flexibility in network design

**Disadvantages:**
- Breaks end-to-end connectivity
- Issues with some protocols (FTP, VoIP)
- Performance overhead
- Troubleshooting complexity

---

**Q11: What is VLAN and its benefits?**

**Answer:**

**VLAN (Virtual LAN):** Logical segmentation of network at Layer 2

**Without VLAN:**
- All devices in same broadcast domain
- Security risk
- Performance issues

**With VLAN:**
- Devices logically grouped
- Separate broadcast domains
- Better security and performance

**Example:**
```
Physical Network: Single Switch with 24 ports

VLAN 10 (Sales):     Ports 1-8
VLAN 20 (HR):        Ports 9-16
VLAN 30 (IT):        Ports 17-24

Even on same physical switch, they're isolated
```

**Benefits:**

1. **Security:** Department isolation
2. **Performance:** Reduced broadcast traffic
3. **Flexibility:** Move users without rewiring
4. **Cost:** No need for separate physical networks
5. **Management:** Centralized control

**VLAN Types:**

**1. Port-based VLAN:**
- Assign ports to VLANs
- Most common

**2. MAC-based VLAN:**
- Based on MAC address
- Device follows user

**3. Protocol-based VLAN:**
- Based on protocol (IP, IPX)

**VLAN Trunking:**
- Carry multiple VLANs on single link
- 802.1Q tagging
- Connects switches

**Inter-VLAN Routing:**
- VLANs isolated by default
- Need Layer 3 device (router/L3 switch)
- Router-on-a-stick or SVI (Switch Virtual Interface)

---

**Q12: Explain the difference between Collision Domain and Broadcast Domain.**

**Answer:**

**Collision Domain:**
- Network segment where collisions can occur
- Devices share bandwidth
- CSMA/CD detects collisions

**Devices:**
- Hub: 1 collision domain (all ports)
- Switch: Each port = 1 collision domain
- Router: Separates collision domains

**Broadcast Domain:**
- Network segment where broadcast reaches
- All devices receive broadcast packets
- Destination MAC: FF:FF:FF:FF:FF:FF

**Devices:**
- Hub: 1 broadcast domain
- Switch: 1 broadcast domain (per VLAN)
- Router: Separates broadcast domains

**Example Network:**
```
10 devices → Hub → Switch → Router → Switch → Hub → 10 devices

Collision Domains:
- Left hub: 1 domain (10 devices share)
- Switch: 2 domains (hub ports)
- Right hub: 1 domain (10 devices share)
Total: 4 collision domains

Broadcast Domains:
- Everything left of router: 1 domain
- Everything right of router: 1 domain
Total: 2 broadcast domains
```

**Why it Matters:**

**Collision Domain:**
- More devices = more collisions
- Reduced performance
- Solution: Use switches

**Broadcast Domain:**
- Large = broadcast storm risk
- Network congestion
- Solution: Use routers or VLANs

**Comparison:**

| Feature | Collision Domain | Broadcast Domain |
|---------|------------------|------------------|
| **Separated by** | Switch, Bridge, Router | Router, L3 Switch, VLAN |
| **Traffic Type** | Unicast collisions | Broadcast packets |
| **Impact** | Performance | Bandwidth |
| **Scope** | Local link | Entire network segment |

---

**Q13: What is the difference between Symmetric and Asymmetric Encryption?**

**Answer:**

**Symmetric Encryption:**

**Concept:** Same key for encryption and decryption

**Examples:** AES, DES, 3DES, Blowfish

**Process:**
1. Sender encrypts with key K
2. Sends encrypted data
3. Receiver decrypts with same key K

**Advantages:**
- Fast (efficient algorithms)
- Less computational overhead
- Suitable for large data

**Disadvantages:**
- Key distribution problem (how to share key securely?)
- Need separate key for each pair of users
- If key compromised, all data exposed

**Use Cases:**
- File encryption
- Database encryption
- VPN tunnels (after key exchange)
- Disk encryption

---

**Asymmetric Encryption:**

**Concept:** Key pair - Public key and Private key

**Examples:** RSA, ECC, Diffie-Hellman

**Process:**
1. Receiver generates key pair (public/private)
2. Receiver shares public key
3. Sender encrypts with public key
4. Only private key can decrypt
5. Receiver decrypts with private key

**Key Properties:**
- Public key: Shared freely
- Private key: Kept secret
- Encrypt with public → Decrypt with private
- Or: Encrypt with private → Decrypt with public (digital signatures)

**Advantages:**
- No key distribution problem
- Digital signatures possible
- Better key management

**Disadvantages:**
- Slow (computationally expensive)
- Not suitable for large data
- Complex algorithms

**Use Cases:**
- SSL/TLS handshake
- Digital signatures
- Email encryption (PGP)
- Key exchange

---

**Hybrid Approach (Real-world):**

**SSL/TLS uses both:**
1. Asymmetric encryption for key exchange
2. Symmetric encryption for actual data transfer

**Example (HTTPS):**
1. Browser and server exchange certificates (asymmetric)
2. Generate session key (asymmetric)
3. All data encrypted with session key (symmetric)

**Comparison:**

| Feature | Symmetric | Asymmetric |
|---------|-----------|------------|
| **Keys** | One shared key | Key pair (public/private) |
| **Speed** | Fast | Slow |
| **Key Distribution** | Difficult | Easy |
| **Use** | Bulk data | Key exchange, signatures |
| **Example** | AES | RSA |
| **Key Size** | 128-256 bits | 2048-4096 bits |

---

**Q14: What is the difference between HTTP and HTTPS?**

**Answer:**

**HTTP (Hypertext Transfer Protocol):**
- Port 80
- Plaintext communication
- No encryption
- Vulnerable to attacks

**HTTPS (HTTP Secure):**
- Port 443
- Encrypted communication (SSL/TLS)
- Secure
- Certificate-based authentication

**Key Differences:**

| Feature | HTTP | HTTPS |
|---------|------|-------|
| **Security** | None | TLS/SSL encryption |
| **Port** | 80 | 443 |
| **URL** | http:// | https:// |
| **Certificate** | Not required | SSL certificate required |
| **Data** | Plaintext | Encrypted |
| **Speed** | Slightly faster | Slightly slower (encryption overhead) |
| **SEO** | Lower ranking | Higher ranking (Google prefers) |
| **Trust** | Low | High (padlock icon) |

**HTTPS Working:**

1. **Client Hello:** Browser initiates SSL handshake
2. **Server Hello:** Server sends SSL certificate
3. **Certificate Validation:** Browser validates certificate
4. **Key Exchange:** Generate session keys
5. **Secure Communication:** All data encrypted with session key

**Why HTTPS:**
- **Confidentiality:** Data encrypted
- **Integrity:** Cannot be modified
- **Authentication:** Verify server identity
- **Trust:** User confidence
- **SEO:** Google ranking factor
- **Required:** Payment pages, login pages

**SSL/TLS Certificate:**
- Issued by Certificate Authority (CA)
- Contains: Domain name, company info, public key, expiry date
- Signed by CA
- Browser verifies signature

**Types of Certificates:**
1. **Domain Validated (DV):** Basic, validates domain ownership
2. **Organization Validated (OV):** Validates organization details
3. **Extended Validation (EV):** Highest level, shows company name in address bar

---

**Q15: Explain Routing Algorithms - Distance Vector vs Link State.**

**Answer:**

**Distance Vector Routing:**

**Principle:** "Tell your neighbors where you can go"

**Examples:** RIP, IGRP

**Algorithm:** Bellman-Ford

**How it Works:**
1. Each router knows distance to direct neighbors
2. Routers exchange entire routing tables periodically
3. Each router updates table based on neighbor information
4. Distance vector = (destination, distance, next hop)

**RIP Example:**
```
Router A's table:
Destination    Distance    Next Hop
B              1           B
C              2           B
D              3           B

(A doesn't know how B reaches C, just that via B = 2 hops)
```

**Characteristics:**
- Periodic updates (RIP: 30 seconds)
- Entire table exchanged
- Slow convergence
- Count-to-infinity problem

**Advantages:**
- Simple to implement
- Low memory requirement
- Easy configuration

**Disadvantages:**
- Slow convergence
- Count-to-infinity problem
- Inefficient (entire table sent)
- Limited scalability (RIP max 15 hops)

---

**Link State Routing:**

**Principle:** "Everyone knows everything about the network"

**Examples:** OSPF, IS-IS

**Algorithm:** Dijkstra's shortest path

**How it Works:**
1. Each router discovers neighbors (HELLO packets)
2. Each router measures cost to neighbors
3. Each router broadcasts Link State Packets (LSP) to all routers
4. All routers build identical topology database
5. Each router runs Dijkstra to find shortest paths

**OSPF Process:**
```
1. Discover neighbors: Send HELLO
2. Build Link State Database (LSDB)
3. Flood LSPs to all routers
4. All routers have same LSDB
5. Run SPF (Shortest Path First) algorithm
6. Build routing table
```

**Characteristics:**
- Event-triggered updates
- Only changes flooded
- Fast convergence
- Complete topology knowledge

**Advantages:**
- Fast convergence
- Scalable (areas in OSPF)
- Loop-free (complete topology)
- Efficient updates (only changes)
- Supports VLSM and CIDR

**Disadvantages:**
- Complex configuration
- High CPU and memory usage
- More complex protocols
- Initial flooding intensive

---

**Comparison:**

| Feature | Distance Vector | Link State |
|---------|----------------|------------|
| **Algorithm** | Bellman-Ford | Dijkstra |
| **Knowledge** | Only neighbors | Complete topology |
| **Updates** | Periodic | Event-triggered |
| **What Sent** | Entire table | Only changes |
| **Convergence** | Slow | Fast |
| **Loops** | Possible | No |
| **Scalability** | Limited | Better |
| **Complexity** | Simple | Complex |
| **Memory** | Low | High |
| **CPU** | Low | High |
| **Example** | RIP (hop count) | OSPF (cost) |
| **Metric** | Simple (hops) | Flexible (cost) |

**Real-World Usage:**
- **Small Networks:** RIP (simple, sufficient)
- **Enterprise:** OSPF (scalable, fast)
- **ISP Core:** IS-IS (very scalable)
- **Internet:** BGP (path vector, different type)

---

**Q16: What is Congestion Control and how does TCP implement it?**

**Answer:**

**Congestion:** Network overload due to too much traffic

**Signs:**
- Packet loss
- Long delays
- Timeouts

**TCP Congestion Control Mechanisms:**

**1. Slow Start:**
- Begin conservatively
- cwnd (congestion window) = 1 MSS
- Double cwnd every RTT (exponential growth)
- Continue until threshold or loss

**Example:**
```
RTT 1: cwnd = 1 MSS
RTT 2: cwnd = 2 MSS
RTT 3: cwnd = 4 MSS
RTT 4: cwnd = 8 MSS
...
```

**2. Congestion Avoidance:**
- After threshold reached
- Linear growth
- cwnd += 1 MSS per RTT
- Additive Increase

**3. Fast Retransmit:**
- 3 duplicate ACKs = loss indication
- Retransmit immediately
- Don't wait for timeout

**4. Fast Recovery:**
- After fast retransmit
- threshold = cwnd / 2
- cwnd = threshold
- Enter congestion avoidance (not slow start)

**TCP Congestion Control Phases:**

```
cwnd
  |
  |     /|              Congestion
  |    / |  Slow       Avoidance
  |   /  |  Start      /------
  |  /   |           /
  | /    |         /
  |/_____|_______/____________ time
       threshold   3 dup ACKs
       reached     (fast retransmit
                    & recovery)
```

**AIMD (Additive Increase Multiplicative Decrease):**
- **Increase:** Add 1 MSS per RTT (linear)
- **Decrease:** Divide cwnd by 2 on loss (exponential)

**Why AIMD:**
- Fair resource allocation
- Stable convergence
- Responsive to congestion

**TCP Variants:**
- **Tahoe:** Slow start after any loss
- **Reno:** Fast recovery for dup ACKs
- **NewReno:** Improved fast recovery
- **CUBIC:** Default in Linux (modern)
- **BBR:** Bottleneck Bandwidth and RTT (Google)

---

**Q17: What is the difference between Guided and Unguided Media?**

**Answer:**

**Guided Media (Wired):**

**Definition:** Physical medium that guides signals

**Types:**

**1. Twisted Pair:**
- Copper wires twisted
- UTP (Unshielded) and STP (Shielded)
- Cat5e, Cat6, Cat7
- **Use:** Ethernet, telephone
- **Distance:** Up to 100m
- **Speed:** Up to 10 Gbps

**2. Coaxial Cable:**
- Central conductor + shield
- Better shielding than twisted pair
- **Use:** Cable TV, cable internet
- **Distance:** Up to 500m
- **Speed:** Up to 10 Gbps

**3. Fiber Optic:**
- Glass/plastic core
- Light signals
- Single-mode and Multi-mode
- **Use:** Long distance, backbone
- **Distance:** Up to 100+ km
- **Speed:** Up to 100 Tbps

**Advantages:**
- Higher security
- Better quality
- Higher bandwidth
- Less interference

**Disadvantages:**
- Installation cost
- Difficult to modify
- Limited mobility

---

**Unguided Media (Wireless):**

**Definition:** No physical medium, signals travel through air/space

**Types:**

**1. Radio Waves:**
- 3 KHz - 1 GHz
- Omnidirectional
- Penetrates walls
- **Use:** Wi-Fi, Bluetooth, FM radio
- **Distance:** Varies (few meters to kilometers)

**2. Microwaves:**
- 1 GHz - 300 GHz
- Line of sight
- Cannot penetrate obstacles
- **Types:**
  - Terrestrial: Tower-based
  - Satellite: Space-based
- **Use:** Long distance communication, satellite

**3. Infrared:**
- 300 GHz - 400 THz
- Line of sight
- Short range
- Cannot penetrate walls
- **Use:** TV remotes, IrDA

**Advantages:**
- Mobility
- Easy installation
- Flexible
- Cost-effective for difficult terrain

**Disadvantages:**
- Less secure
- Interference
- Lower bandwidth
- Weather-dependent

**Comparison:**

| Feature | Guided | Unguided |
|---------|--------|----------|
| **Medium** | Physical | Air/space |
| **Security** | High | Low |
| **Installation** | Difficult | Easy |
| **Cost** | High | Low-Moderate |
| **Mobility** | No | Yes |
| **Interference** | Low | High |
| **Bandwidth** | Higher | Lower |
| **Distance** | Limited by cable | Variable |
| **Example** | Ethernet | Wi-Fi |

---

**Q18: What is Bluetooth? Explain its features.**

**Answer:**

**Bluetooth:** Wireless technology for short-range data exchange

**Standard:** IEEE 802.15.1 (WPAN - Wireless Personal Area Network)

**Frequency:** 2.4 GHz ISM band

**Range:**
- Class 1: Up to 100 meters (industrial)
- Class 2: Up to 10 meters (most common - phones, headsets)
- Class 3: Up to 1 meter

**Key Features:**

**1. Low Power Consumption:**
- Designed for battery-powered devices
- Bluetooth Low Energy (BLE) for IoT

**2. Frequency Hopping:**
- Hops between 79 channels
- 1600 hops per second
- Reduces interference
- Better security

**3. Piconet:**
- One master, up to 7 active slaves
- Master controls communication
- Slaves respond when polled

**4. Scatternet:**
- Multiple piconets interconnected
- Device can be master in one, slave in another

**5. Pairing:**
- Devices must pair before connecting
- Authentication using PIN or passkey
- Encrypted communication

**Bluetooth Versions:**

**Bluetooth 1.x:**
- Speed: 721 Kbps
- Initial version

**Bluetooth 2.0 + EDR (Enhanced Data Rate):**
- Speed: 3 Mbps
- Lower power consumption

**Bluetooth 3.0 + HS (High Speed):**
- Speed: 24 Mbps
- Uses Wi-Fi for data transfer

**Bluetooth 4.0 (BLE - Bluetooth Low Energy):**
- Very low power
- IoT devices
- Fitness trackers, smartwatches

**Bluetooth 5.0:**
- Speed: 2 Mbps
- Range: 240 meters (4x improvement)
- Concurrent connections

**Bluetooth 5.3 (Latest):**
- Improved efficiency
- Better coexistence with Wi-Fi
- LE Audio support

**Bluetooth Profiles:**
- **A2DP:** Advanced Audio Distribution (music streaming)
- **HFP:** Hands-Free Profile (phone calls)
- **HSP:** Headset Profile
- **SPP:** Serial Port Profile
- **HID:** Human Interface Device (keyboard, mouse)
- **FTP:** File Transfer Profile

**Applications:**
- Wireless headphones/earbuds
- Speakers
- Keyboard and mouse
- File transfer
- Smartwatches and fitness bands
- Car audio systems
- Medical devices
- IoT sensors

**Advantages:**
- Universal standard
- Low power
- Easy to use (plug and play)
- Secure (encryption)
- Inexpensive

**Disadvantages:**
- Limited range
- Lower speed than Wi-Fi
- Interference with Wi-Fi (same frequency)
- Limited simultaneous connections

**Bluetooth vs Wi-Fi:**

| Feature | Bluetooth | Wi-Fi |
|---------|-----------|-------|
| **Range** | 1-100m | 30-100m (more) |
| **Speed** | Up to 3 Mbps | Up to Gbps |
| **Power** | Very low | Higher |
| **Use** | Device pairing | Internet access |
| **Security** | Pairing | Password |
| **Standard** | 802.15.1 | 802.11 |

---

**Q19: Explain Error Detection techniques in detail.**

**Answer:**

**Error Detection:** Identifying errors in transmitted data

**Why Needed:**
- Transmission media introduces errors
- Noise, attenuation, interference
- Ensure data integrity

**Techniques:**

**1. Parity Check:**

**Single Bit Parity (VRC - Vertical Redundancy Check):**

**Even Parity:**
- Total number of 1s should be even
- Example: Data = 1011001 (four 1s)
- Parity bit = 0 (to keep even)
- Transmitted: 10110010

**Odd Parity:**
- Total number of 1s should be odd
- Example: Data = 1011001
- Parity bit = 1 (to make odd)
- Transmitted: 10110011

**Detection:**
- Receiver counts 1s
- If parity doesn't match, error detected

**Limitation:**
- Detects only odd number of errors
- Cannot detect even number of errors
- Cannot correct errors

**Two-Dimensional Parity (LRC - Longitudinal Redundancy Check):**

**Example:**
```
Data arranged in matrix:
1 0 1 1 | 1  ← Row parity
0 1 1 0 | 0
1 1 0 1 | 1
1 0 1 1 | 1
---------
1 0 1 1   ← Column parity
```

**Better Detection:**
- Can detect burst errors
- Can locate error position (row + column)
- Still cannot detect all errors

---

**2. Checksum:**

**Process:**

**Sender:**
1. Divide data into segments (typically 16-bit words)
2. Add all segments using 1's complement arithmetic
3. Take 1's complement of sum
4. This is checksum
5. Append to data

**Receiver:**
1. Receive data + checksum
2. Add all segments including checksum
3. Take 1's complement
4. If result is all 0s, no error
5. If non-zero, error detected

**Example:**
```
Segment 1: 1011001101001010
Segment 2: 0110101100110101
          ----------------
Sum:       0001111001111111
1's comp:  1110000110000000 ← Checksum

At receiver:
Segment 1: 1011001101001010
Segment 2: 0110101100110101
Checksum:  1110000110000000
          ----------------
Sum:       1111111111111111
1's comp:  0000000000000000 ← No error
```

**Properties:**
- Simple to implement
- Used in IP, TCP, UDP headers
- Can detect most errors
- Cannot detect all errors (some patterns slip through)

**Performance:**
- Better than simple parity
- Not as strong as CRC

---

**3. Cyclic Redundancy Check (CRC):**

**Most powerful error detection method**

**Process:**

**Sender:**
1. Represent data as polynomial
2. Choose generator polynomial (G) - agreed beforehand
3. Append n zeros to data (n = degree of G)
4. Divide by G using modulo-2 division (XOR)
5. Remainder is CRC
6. Replace appended zeros with CRC
7. Transmit data + CRC

**Receiver:**
1. Receive data + CRC
2. Divide by same generator G
3. If remainder is 0, no error
4. If non-zero, error detected

**Modulo-2 Division:**
- Like binary division but uses XOR instead of subtraction
- No borrow concept
- 1 + 1 = 0, 1 + 0 = 1, 0 + 0 = 0

**Example:**

```
Data:      1101011011
Generator: 10011 (degree = 4, so append 4 zeros)
Data + 0s: 11010110110000

Modulo-2 Division:
                10100111
        ___________________
10011 ) 11010110110000
        10011           ← XOR with generator
        -----
         10111
         10011
         -----
          01001
          00000
          -----
           10011
           10011
           -----
            00001
            00000
            -----
             00010
             00000
             -----
              00100
              00000
              -----
               01000
               00000
               -----
                10000
                10011
                -----
                 0011  ← Remainder (CRC)

Transmitted: 11010110110011
             (Data + CRC)
```

**Common CRC Standards:**

**CRC-8:**
- 8-bit CRC
- Generator: x^8 + x^2 + x + 1
- Used in: ATM header

**CRC-16:**
- 16-bit CRC
- Generator: x^16 + x^15 + x^2 + 1
- Used in: USB, Modbus

**CRC-32:**
- 32-bit CRC
- Generator: x^32 + x^26 + x^23 + ... + 1
- Used in: Ethernet, Wi-Fi, ZIP, PNG

**CRC-CCITT:**
- 16-bit CRC
- Generator: x^16 + x^12 + x^5 + 1
- Used in: Bluetooth, X.25, HDLC

**CRC Properties:**

**Detection Capability:**
- Detects all single-bit errors
- Detects all double-bit errors
- Detects odd number of errors (if G contains x+1)
- Detects burst errors < length of CRC

**Advantages:**
- Very effective
- Industry standard
- Fast hardware implementation
- Better than checksum

**Disadvantages:**
- More complex than parity/checksum
- Cannot correct errors (only detect)

---

**Comparison of Error Detection Methods:**

| Method | Overhead | Detection Power | Complexity | Use |
|--------|----------|----------------|------------|-----|
| **Parity** | 1 bit | Weak | Simple | Simple systems |
| **Checksum** | 16-32 bits | Moderate | Moderate | IP, TCP, UDP |
| **CRC** | 8-32 bits | Strong | Complex | Ethernet, Wi-Fi |

**Error Detection vs Correction:**

**Detection:** Only identifies errors (all above methods)
**Correction:** Can fix errors (Hamming code, Reed-Solomon)

Detection is simpler and more common. If error detected:
- Request retransmission (ARQ - Automatic Repeat Request)
- Or use error correction (FEC - Forward Error Correction)

---

**Q20: What is the difference between Circuit Switching and Packet Switching?**

**Answer:**

**Circuit Switching:**

**Definition:** Dedicated path established for entire communication duration

**Example:** Traditional telephone network (PSTN)

**Process:**
1. **Circuit Establishment:** Dedicated path reserved
2. **Data Transfer:** Data flows along dedicated path
3. **Circuit Termination:** Path released after communication

**Characteristics:**
- Dedicated bandwidth
- Fixed path
- Continuous connection
- Resources reserved for entire duration

**Phases:**
1. **Setup:** Establish connection (takes time)
2. **Data Transfer:** Actual communication
3. **Teardown:** Release resources

**Advantages:**
- Guaranteed bandwidth
- No queuing delays during transfer
- Predictable performance
- Suitable for real-time (voice calls)

**Disadvantages:**
- Inefficient (bandwidth wasted when idle)
- Setup delay
- Resources blocked even if not using
- Fixed data rate
- Expensive
- Not resilient (if path fails, call drops)

**Types:**
- **Space Division:** Physical separation (crossbar switch)
- **Time Division:** Time slots
- **Frequency Division:** Frequency bands

---

**Packet Switching:**

**Definition:** Data divided into packets, each routed independently

**Example:** Internet, email, web browsing

**Process:**
1. Data divided into packets
2. Each packet has header (source, destination, sequence)
3. Packets routed independently
4. May take different paths
5. Reassembled at destination

**Characteristics:**
- No dedicated path
- Shared resources
- Store-and-forward
- Statistical multiplexing

**Types:**

**1. Datagram (Connectionless):**
- Each packet independent
- No connection setup
- Packets may arrive out of order
- Each packet has full addressing
- Example: IP, UDP

**2. Virtual Circuit (Connection-oriented):**
- Logical connection established first
- All packets follow same path
- Packets arrive in order
- Example: ATM, Frame Relay, MPLS

**Advantages:**
- Efficient bandwidth usage
- No setup delay (datagram)
- Resilient (alternate paths if failure)
- Multiple connections share resources
- Cost-effective

**Disadvantages:**
- Variable delays (queuing)
- Packets may be lost
- Reassembly overhead
- Not suitable for real-time (unless QoS)
- Jitter in packet arrival

---

**Comparison:**

| Feature | Circuit Switching | Packet Switching |
|---------|-------------------|------------------|
| **Connection** | Dedicated | Shared |
| **Setup** | Required | Not required (datagram) |
| **Path** | Fixed | Dynamic |
| **Bandwidth** | Fixed, dedicated | Shared, variable |
| **Efficiency** | Low (wasted when idle) | High |
| **Delay** | Fixed (after setup) | Variable |
| **Reliability** | High (dedicated) | Lower (congestion) |
| **Cost** | High | Lower |
| **Use** | Voice calls | Data networks |
| **Example** | Telephone | Internet |
| **Resource Usage** | Reserved | On-demand |
| **Failure Impact** | Connection drops | Packets rerouted |

**Modern Hybrid:**
- **VoIP:** Voice over packet-switched networks
- Uses QoS mechanisms
- Best of both worlds

**When to Use:**

**Circuit Switching:**
- Constant bitrate traffic
- Real-time requirements
- Guaranteed QoS needed
- Example: Live streaming with SLA

**Packet Switching:**
- Bursty traffic
- Multiple connections
- Cost-effective needed
- Example: Web, email, file transfer

---

## EXAM PREPARATION TIPS

### Important Topics for 10 Marks Questions:

**Unit 1:**
1. OSI Model (all 7 layers with functions, protocols, examples)
2. TCP/IP Model (4 layers comparison with OSI)

**Unit 2:**
1. Network Topologies (star, ring, bus, mesh with diagrams, advantages/disadvantages)
2. Transmission Media (guided: twisted pair, coaxial, fiber; unguided: radio, microwave, infrared)
3. Network Types (LAN, MAN, WAN with protocols)

**Unit 3:**
1. Error Detection and Correction (parity, checksum, CRC with examples)
2. Flow Control (Stop-and-Wait, Go-Back-N, Selective Repeat)

**Unit 4:**
1. Routing (Distance Vector vs Link State with examples)
2. IPv4 packet format with all fields explained
3. Subnetting with calculations

**Unit 5:**
1. TCP (segment format, 3-way handshake, 4-way termination)
2. TCP vs UDP comparison

**Unit 6:**
1. Application Layer Protocols (HTTP, FTP, SMTP, DNS with working)
2. Email system (SMTP, POP3, IMAP)

### Short Answer Topics (3 Marks Each):

- Guided media types
- Data Link Layer functions
- Protocol definition
- Bluetooth features
- MAC Layer
- TCP characteristics
- Transport Layer services
- Network congestion
- ISDN channels
- Multimedia elements
- Telnet
- NFS
- SNMP
- Router-Bridge difference
- Hubs vs Switches
- Baseband vs Broadband
- Active vs Passive sockets
- LAN/WAN/MAN protocols
- DHCP
- ARP

### How to Answer 10-Mark Questions:

**Structure:**
1. **Introduction** (1 mark): Define the concept
2. **Main Content** (7-8 marks):
   - Detailed explanation
   - Diagrams where applicable
   - Examples
   - Sub-topics covered
3. **Conclusion** (1 mark): Summary or advantages/disadvantages

**Example Structure for "OSI Model":**
- Introduction: What is OSI, why needed
- Layer 7 - Application: Function, protocols, example
- Layer 6 - Presentation: Function, examples
- Layer 5 - Session: Function, examples
- Layer 4 - Transport: Function, TCP/UDP
- Layer 3 - Network: Function, IP, routing
- Layer 2 - Data Link: Function, MAC, frames
- Layer 1 - Physical: Function, media, signals
- Conclusion: Importance, comparison with TCP/IP

### Diagram Practice:

**Must-know diagrams:**
1. OSI Model (7 layers)
2. TCP/IP Model (4 layers)
3. Star Topology
4. Ring Topology
5. Bus Topology
6. Mesh Topology
7. TCP 3-way handshake
8. TCP 4-way termination
9. IPv4 packet format
10. TCP segment format
11. DNS hierarchy
12. Email architecture
13. Hub vs Switch network
14. Collision vs Broadcast domain

### Formula to Remember:

**Subnetting:**
- Subnets = 2^n (n = borrowed bits)
- Hosts = 2^h - 2 (h = remaining host bits)

**Efficiency:**
- Stop-and-Wait = 1 / (1 + 2a)
- a = Propagation time / Transmission time

**CRC:**
- Append zeros = Degree of generator polynomial

### Time Management in Exam:

**Section A (40 marks - 4 questions × 10 marks):**
- Allocate 25 minutes per question
- Total: 100 minutes

**Section B (30 marks - 10 questions × 3 marks):**
- Allocate 5 minutes per question
- Total: 50 minutes

**Review:** 10 minutes

**Total:** 160 minutes (within 3 hours)

### Writing Tips:

1. **Start with definition** - Every answer should begin with a clear definition
2. **Use headings** - Makes answer organized and easy to read
3. **Include diagrams** - Worth more than words, label clearly
4. **Give examples** - Real-world examples show understanding
5. **Compare when possible** - Comparison tables score well
6. **Write in points** for clarity
7. **Use technical terms** correctly
8. **Underline key terms** - Shows important concepts
9. **Conclusion** - Always summarize
10. **Write legibly** - Presentation matters

### Last-Minute Revision Checklist:

**Day Before Exam:**
- [ ] Revise all definitions
- [ ] Practice all diagrams
- [ ] Review comparison tables
- [ ] Go through previous year papers
- [ ] Revise short answer topics
- [ ] Formula revision
- [ ] Protocol port numbers
- [ ] OSI vs TCP/IP layers

**Morning of Exam:**
- [ ] Quick revision of definitions
- [ ] Protocol names and ports
- [ ] Key differences (TCP vs UDP, Hub vs Switch, etc.)
- [ ] Formula verification

---

## CONCLUSION

This comprehensive guide covers all aspects of Computer Networks for your BCA 4th Semester exam. Focus on understanding concepts rather than memorizing, as questions may be framed differently. Practice diagrams regularly and try to explain concepts in your own words.

**Key to Success:**
1. Understand the "why" behind each concept
2. Practice writing answers within time limits
3. Draw diagrams for better scores
4. Review previous year papers
5. Focus on application-oriented questions
6. Keep your answers structured and organized

**All the best for your exam and future interviews!**

Remember: Networking is not just theory - it's the backbone of modern computing. Understanding these concepts will help you throughout your career in Computer Science.

---

*"The Internet is becoming the town square for the global village of tomorrow." - Bill Gates*

**End of Notes**
