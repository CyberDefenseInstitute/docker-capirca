
header {
  comment:: "'Firewall ACL for intra server segment ACL'"
  target:: cisco server extended
}

term accept-same-segment {
  comment:: "'Allow tcp/udp from INTRA_SERVER'"
  source-address:: INTRA_SERVER
  destination-address:: INTRA_SERVER
  action:: accept
}

term accept-ssh-replies {
  comment:: "'Allow ssh tcp replies to NOC_SEGMENT.'"
  destination-address:: NOC_SEGMENT
  source-address:: INTRA_SERVER
  source-port:: SSH
  protocol:: tcp
  option:: tcp-established
  action:: accept
}

term deny-ssh-request {
  comment:: "'Deny ssh tcp replies to INTRA_OFFICE.'"
  destination-address:: INTRA_OFFICE
  source-port:: SSH
  protocol:: tcp
  action:: deny
}

term accept-tcp-replies {
  comment:: "'Allow tcp replies to INTRA_OFFICE.'"
  destination-address:: INTRA_OFFICE
  source-address:: INTRA_SERVER
  source-port:: HTTPS
  protocol:: tcp
  option:: tcp-established
  action:: accept
}

#include './includes-extended/rfc1918-networks-blocking.inc'

