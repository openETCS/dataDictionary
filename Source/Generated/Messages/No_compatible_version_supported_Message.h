
#ifndef NO_COMPATIBLE_VERSION_SUPPORTED_Message_H_INCLUDED
#define NO_COMPATIBLE_VERSION_SUPPORTED_Message_H_INCLUDED

#include "EuroradioMessage.h"
#include "Bitstream.h"
#include <iostream>

struct No_compatible_version_supported_Message : public EuroradioMessage
{
    uint16_t  L_MESSAGE        ;  // # 10
    uint32_t  T_TRAIN          ;  // # 32
    uint32_t  NID_ENGINE       ;  // # 24


    No_compatible_version_supported_Message() : EuroradioMessage(154) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
               << +header.NID_MESSAGE  << ","
               << +L_MESSAGE << ","
               << +T_TRAIN << ","
               << +NID_ENGINE << ")";
    }

    bool equals(const EuroradioMessage& p) const override
    {
        if (auto q = dynamic_cast<const No_compatible_version_supported_Message*>(&p))
        {
            bool status = true;

            status = status && (header.NID_MESSAGE == q->header.NID_MESSAGE);
            status = status && (L_MESSAGE == q->L_MESSAGE);
            status = status && (T_TRAIN == q->T_TRAIN);
            status = status && (NID_ENGINE == q->NID_ENGINE);

            return status;
        }

        return false;
    }

    bool decode(Bitstream& stream);

    bool encode(Bitstream& stream) const;
};

typedef std::shared_ptr<No_compatible_version_supported_Message> No_compatible_version_supported_MessagePtr;

#endif // NO_COMPATIBLE_VERSION_SUPPORTED_Message_H_INCLUDED

