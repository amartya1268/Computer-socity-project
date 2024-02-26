Developed an RFID scanner using a microcontroller that uses small radio frequency identification devices for identification purposes. RFID uses electromagnetic fields to transfer data over short distances. This system requires the tag, which is used to gain access, a read and write device, which will be used to read and store, respectively, the UID (identification) of the tag, and a host system application for the collection of the data and processing and transferring of the data. A two-way radio transmitter/receiver are used. It sends a signal to the tag and reads its response.

The system is split into three modules:
* Reading the UID from RFIDs
* Processing the UID read from the RFIDs and verifying it with the hard-coded access credentials.
* Allowing access to the matched UID and preventing all other RFIDs from gaining access. The owner can also be notified when there is an attempt for unauthorized access.
