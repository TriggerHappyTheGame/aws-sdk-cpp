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

#include <aws/ec2/model/LoadPermissionRequest.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::Utils::Xml;
using namespace Aws::Utils;

namespace Aws
{
namespace EC2
{
namespace Model
{

LoadPermissionRequest::LoadPermissionRequest() : 
    m_group(PermissionGroup::NOT_SET),
    m_groupHasBeenSet(false),
    m_userIdHasBeenSet(false)
{
}

LoadPermissionRequest::LoadPermissionRequest(const XmlNode& xmlNode) : 
    m_group(PermissionGroup::NOT_SET),
    m_groupHasBeenSet(false),
    m_userIdHasBeenSet(false)
{
  *this = xmlNode;
}

LoadPermissionRequest& LoadPermissionRequest::operator =(const XmlNode& xmlNode)
{
  XmlNode resultNode = xmlNode;

  if(!resultNode.IsNull())
  {
    XmlNode groupNode = resultNode.FirstChild("Group");
    if(!groupNode.IsNull())
    {
      m_group = PermissionGroupMapper::GetPermissionGroupForName(StringUtils::Trim(Aws::Utils::Xml::DecodeEscapedXmlText(groupNode.GetText()).c_str()).c_str());
      m_groupHasBeenSet = true;
    }
    XmlNode userIdNode = resultNode.FirstChild("UserId");
    if(!userIdNode.IsNull())
    {
      m_userId = Aws::Utils::Xml::DecodeEscapedXmlText(userIdNode.GetText());
      m_userIdHasBeenSet = true;
    }
  }

  return *this;
}

void LoadPermissionRequest::OutputToStream(Aws::OStream& oStream, const char* location, unsigned index, const char* locationValue) const
{
  if(m_groupHasBeenSet)
  {
      oStream << location << index << locationValue << ".Group=" << PermissionGroupMapper::GetNameForPermissionGroup(m_group) << "&";
  }

  if(m_userIdHasBeenSet)
  {
      oStream << location << index << locationValue << ".UserId=" << StringUtils::URLEncode(m_userId.c_str()) << "&";
  }

}

void LoadPermissionRequest::OutputToStream(Aws::OStream& oStream, const char* location) const
{
  if(m_groupHasBeenSet)
  {
      oStream << location << ".Group=" << PermissionGroupMapper::GetNameForPermissionGroup(m_group) << "&";
  }
  if(m_userIdHasBeenSet)
  {
      oStream << location << ".UserId=" << StringUtils::URLEncode(m_userId.c_str()) << "&";
  }
}

} // namespace Model
} // namespace EC2
} // namespace Aws
