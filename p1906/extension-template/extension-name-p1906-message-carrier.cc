/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 *  Copyright � 2015 by IEEE.
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
#include "ns3/packet.h"
#include "extension-name-p1906-message-carrier.h"


namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("ExtensionNameP1906MessageCarrier");

TypeId ExtensionNameP1906MessageCarrier::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::EstensionNameP1906MessageCarrier")
    .SetParent<P1906MessageCarrier> ();
  return tid;
}

ExtensionNameP1906MessageCarrier::ExtensionNameP1906MessageCarrier ()
{
  NS_LOG_FUNCTION (this);
  SetMessage (0);
}

ExtensionNameP1906MessageCarrier::~ExtensionNameP1906MessageCarrier ()
{
  NS_LOG_FUNCTION (this);
  SetMessage (0);
}


} // namespace ns3
