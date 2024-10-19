#include "SerialData.h"


SerialData::SerialData(uint8_t size)
{
    op_mode = SERIAL_OP_MODE_EDITABLE;
    frame_size = size;
    frame_pos = 0;
    frame = new SerialValue[size];
}

SerialData::~SerialData()
{
    delete[] frame;
}


void SerialData::add_generic_value(const char* name, size_t size, SerialValueType type)
{
    if (op_mode == SERIAL_OP_MODE_EDITABLE && frame_pos < frame_size)
    {
        frame[frame_pos].name = name;
        frame[frame_pos].value = new uint8_t[size];
        frame[frame_pos].size = size;
        frame[frame_pos].type = type;
        frame_pos++;
    }
}