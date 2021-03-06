﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/ec2/model/ModifyVpnTunnelOptionsRequest.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

using namespace Aws::EC2::Model;
using namespace Aws::Utils;

ModifyVpnTunnelOptionsRequest::ModifyVpnTunnelOptionsRequest() : 
    m_vpnConnectionIdHasBeenSet(false),
    m_vpnTunnelOutsideIpAddressHasBeenSet(false),
    m_tunnelOptionsHasBeenSet(false),
    m_dryRun(false),
    m_dryRunHasBeenSet(false)
{
}

Aws::String ModifyVpnTunnelOptionsRequest::SerializePayload() const
{
  Aws::StringStream ss;
  ss << "Action=ModifyVpnTunnelOptions&";
  if(m_vpnConnectionIdHasBeenSet)
  {
    ss << "VpnConnectionId=" << StringUtils::URLEncode(m_vpnConnectionId.c_str()) << "&";
  }

  if(m_vpnTunnelOutsideIpAddressHasBeenSet)
  {
    ss << "VpnTunnelOutsideIpAddress=" << StringUtils::URLEncode(m_vpnTunnelOutsideIpAddress.c_str()) << "&";
  }

  if(m_tunnelOptionsHasBeenSet)
  {
    m_tunnelOptions.OutputToStream(ss, "TunnelOptions");
  }

  if(m_dryRunHasBeenSet)
  {
    ss << "DryRun=" << std::boolalpha << m_dryRun << "&";
  }

  ss << "Version=2016-11-15";
  return ss.str();
}


void  ModifyVpnTunnelOptionsRequest::DumpBodyToUrl(Aws::Http::URI& uri ) const
{
  uri.SetQueryString(SerializePayload());
}
