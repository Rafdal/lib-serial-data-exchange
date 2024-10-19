#ifndef SERIAL_DATA_H
#define SERIAL_DATA_H

#include <stddef.h>
#include <stdint.h>

typedef enum _SerialValueType_ {
    SERIAL_TYPE_INT8 = 0,
    SERIAL_TYPE_UINT8,
    SERIAL_TYPE_INT16,
    SERIAL_TYPE_UINT16,
    SERIAL_TYPE_INT32,
    SERIAL_TYPE_UINT32,
    SERIAL_TYPE_FLOAT,
    SERIAL_TYPE_DOUBLE,
    SERIAL_TYPE_STRING,
    SERIAL_TYPE_BOOL,
    SERIAL_TYPE_CHAR,
    SERIAL_TYPE_BYTE,
    SERIAL_TYPE_ARRAY,
    SERIAL_TYPE_UNKNOWN
} SerialValueType;

/**
 * @brief Structure to hold a serial value
 */
typedef struct SerialValue {
    const char* name;
    void* value;
    size_t size;
    SerialValueType type;

    SerialValue() {
        name = NULL;
        value = NULL;
        size = 0;
        type = SERIAL_TYPE_UNKNOWN;
    }
};

/**
 * @brief Enumeration to define the operation mode of the serial data
 * 
 * SERIAL_OP_MODE_EDITABLE: The frame is editable and values can be added to it
 * SERIAL_OP_MODE_FIXED: The frame is fixed and no more values can be added to it, but the values can be set and read
 */
typedef enum {
    SERIAL_OP_MODE_EDITABLE = 0,
    SERIAL_OP_MODE_FIXED,
    SERIAL_OP_MODE_UNKNOWN,
} SerialOpMode;


/**
 * @brief Class to handle serial data exchange
 */
class SerialData
{
private:
    SerialOpMode op_mode;
    uint8_t frame_size;
    uint8_t frame_pos;
    SerialValue* frame = NULL;

    void add_generic_value(const char* name, size_t size, SerialValueType type);

public:
    SerialData(uint8_t size);
    ~SerialData();

    // add values to the frame in editable mode
    
    void add_value(const char* name, uint8_t value)
    {
        }
    void add_value(const char* name, int8_t value);
    void add_value(const char* name, uint16_t value);
    void add_value(const char* name, int16_t value);
    void add_value(const char* name, uint32_t value);
    void add_value(const char* name, int32_t value);
    void add_value(const char* name, float value);
    void add_value(const char* name, double value);
    void add_value(const char* name, const char* value);
    void add_value(const char* name, bool value);
    void add_value(const char* name, char value);
    void add_value(const char* name, uint8_t* value, size_t size);   // array

    void fix_frame_format();    // stop adding values and fix the frame format

};




#endif // SERIAL_DATA_H