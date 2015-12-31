#ifndef RTP_H_
#define RTP_H_


extern void sx_mgmt_rtp_init(
    void
    );

extern void sx_mgmt_rtp_open(
    void
    );

extern void sx_mgmt_rtp_activate(
    unsigned int    id,
    unsigned int    ip,
    unsigned short  port
    );

extern void sx_mgmt_rtp_reset(
    unsigned int    id
    );

#endif // RTP_H_
