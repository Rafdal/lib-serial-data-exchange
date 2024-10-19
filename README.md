# lib-serial-data-exchange

This library provides a simple way to exchange high level data between am embedded device (C/C++) and a host application (Python).

The main idea is to define a data frame with named fields and their types. The names and types are transmitted just once, at the beginning of the communication. Then, the data is exchanged in the form of a binary stream in order to keep the communication as efficient as possible.

## How it works

The library is composed of two parts: the host side and the device side. Both parts follows the same flow diagram:

```mermaid
sequenceDiagram
    participant H as Host (Python)
    participant D as Device (C/C++)
    H->>D: Connect
    D->>H: Define data frame
    H->>D: Define data frame
    H->>D: Send data
    D->>H: Receive data
    H->>D: Disconnect
    D->>H: Disconnect
```

## Flowchart

```mermaid
flowchart TD
    A0[Device] --> A1(Send Routine) 
    A1 --> B{{¿Data frame sent?}}
    B --> |Yes| C(Load data)
    C --> D(Send data)
    B --> |No| G(Send data frame)

    H0[Host] --> H1(Receive Routine)
    H1 --> I{{¿Is data frame format set?}}
    I --> |Yes| J(Parse data)
    I --> |No| L(Request data frame)
```

### Host side (Python)

The host side is a Python library that provides a class to define the data frame and a class to exchange

### Device side (C/C++)

The device side is a C/C++ library that provides a class to define the data frame and a class to exchange