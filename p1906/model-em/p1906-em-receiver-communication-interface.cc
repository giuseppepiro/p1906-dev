/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 *  Copyright � 2014 by IEEE.
 *
 *  This source file is an essential part of IEEE P1906.1,
 *  Recommended Practice for Nanoscale and Molecular
 *  Communication Framework.
 *  Verbatim copies of this source file may be used and
 *  distributed without restriction. Modifications to this source
 *  file as permitted in IEEE P1906.1 may also be made and
 *  distributed. All other uses require permission from the IEEE
 *  Standards Department (stds-ipr@ieee.org). All other rights
 *  reserved.
 *
 *  This source file is provided on an AS IS basis.
 *  The IEEE disclaims ANY WARRANTY EXPRESS OR IMPLIED INCLUDING
 *  ANY WARRANTY OF MERCHANTABILITY AND FITNESS FOR USE FOR A
 *  PARTICULAR PURPOSE.
 *  The user of the source file shall indemnify and hold
 *  IEEE harmless from any damages or liability arising out of
 *  the use thereof.
 *
 * Author: Giuseppe Piro - Telematics Lab Research Group
 *                         Politecnico di Bari
 *                         giuseppe.piro@poliba.it
 *                         telematics.poliba.it/piro
 */


#include "ns3/log.h"

#include "p1906-em-receiver-communication-interface.h"
#include "ns3/p1906-net-device.h"
#include <ns3/packet.h>
#include "ns3/p1906-specificity.h"
#include "ns3/p1906-message-carrier.h"
#include "ns3/p1906-communication-interface.h"
#include "ns3/p1906-medium.h"
#include "ns3/p1906-net-device.h"
#include "ns3/p1906-motion.h"
#include "p1906-em-specificity.h"


namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("P1906EMReceiverCommunicationInterface");

TypeId P1906EMReceiverCommunicationInterface::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::P1906EMReceiverCommunicationInterface")
    .SetParent<P1906ReceiverCommunicationInterface> ();
  return tid;
}

P1906EMReceiverCommunicationInterface::P1906EMReceiverCommunicationInterface ()
{
  NS_LOG_FUNCTION (this);
}

P1906EMReceiverCommunicationInterface::~P1906EMReceiverCommunicationInterface ()
{
  NS_LOG_FUNCTION (this);
}

void
P1906EMReceiverCommunicationInterface::HandleReception (Ptr<P1906CommunicationInterface> src, Ptr<P1906CommunicationInterface> dst, Ptr<P1906MessageCarrier> message)
{
  NS_LOG_FUNCTION (this);

  Ptr<P1906EMSpecificity> specificity = GetP1906Specificity ()->GetObject<P1906EMSpecificity> ();
  bool isRxOk = specificity->CheckRxCompatibility (src, dst, message);
  if (isRxOk)
    {
	  NS_LOG_FUNCTION (this << "message received correctly");
	  Ptr<Packet> p = message->GetMessage ();
	  //xxx forward to upper layer
    }
  else
    {
	  NS_LOG_FUNCTION (this << "message NOT received correctly");
	  //ignore the message carrier
    }

}

} // namespace ns3
