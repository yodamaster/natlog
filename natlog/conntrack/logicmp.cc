#include "conntrack.ih"

void Conntrack::logIcmp(ConntrackRecord::Record const &record, 
                        string const &endSeconds, 
                        string endMicroSecs)
{
    endMicroSecs.insert(0, 6 - endMicroSecs.length(), '0');

    d_stdMsg << "from " << 
                ShowSeconds(record.seconds) << ':' << record.musecs << 
            " until " << 
                ShowSeconds(endSeconds) << ':' << endMicroSecs << 
                                    ShowSeconds::utcMarker() << ": icmp " <<
            record.sourceIP << " (via: " << record.viaIP  << ") "
        "to " << record.destIP << endl;
}
