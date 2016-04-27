
#ifndef ATEASYSMS_H
#define ATEASYSMS_H

// includes
#include "../core/ATDev.h"
#include "../core/ISMS.h"

// commands
#define ATDEV_CMD_CPMS PSTR("AT+CPMS=\"SM\",\"SM\",\"SM\"")
#define ATDEV_CMD_CMGF PSTR("AT+CMGF=1")

// strings
#define ATDEV_STR_CMGL PSTR("+CMGL:")
#define ATDEV_STR_CMGR PSTR("+CMGR:")

/**
 * Default AT SMS command handle object
 */
class ATEasySMS : public ISMS, public virtual ATDev
{
    protected:
        
        /**
         * Function to handle all SIM delete request
         */
        uint8_t doDeleteSMS(uint16_t idx, uint8_t flag);

        /**
         * Create a end buffer for CMGL command
         */
        void setCMGLEndBuffer();

    public:

        /**
         * Implement from @see ISMS
         */
        virtual uint8_t initializeSMS();
        virtual uint8_t sendSMS();
        virtual uint8_t receiveSMS(uint16_t idx);
        virtual uint16_t readNextIdxSMS(uint16_t lastIdx = 0);

        virtual uint8_t deleteSMS(uint16_t idx) {
            return this->doDeleteSMS(idx, ATDEV_OPT_CMGD_DEL_IDX);
        }

        virtual uint8_t deleteAllSMS(uint8_t flag) {
            return this->doDeleteSMS(0x0000, flag);
        }
};

#endif

// vim: set sts=4 sw=4 ts=4 et: