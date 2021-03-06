/////////////////////////////////////////////////////////////////////////////
// Authors:     Laurent Pugin and Rodolfo Zitellini
// Created:     2014
// Copyright (c) Authors and others. All rights reserved.
//
// Code generated using a modified version of libmei
// by Andrew Hankinson, Alastair Porter, and Others
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// NOTE: this file was generated with the Verovio libmei version and
// should not be edited because changes will be lost.
/////////////////////////////////////////////////////////////////////////////

#include "atts_edittrans.h"

//----------------------------------------------------------------------------

#include <assert.h>

//----------------------------------------------------------------------------

#include "object.h"

/* #include_block */

namespace vrv {

//----------------------------------------------------------------------------
// AttAgentident
//----------------------------------------------------------------------------

AttAgentident::AttAgentident() : Att()
{
    ResetAgentident();
}

AttAgentident::~AttAgentident()
{
}

void AttAgentident::ResetAgentident()
{
    m_agent = "";
}

bool AttAgentident::ReadAgentident(pugi::xml_node element)
{
    bool hasAttribute = false;
    if (element.attribute("agent")) {
        this->SetAgent(StrToStr(element.attribute("agent").value()));
        element.remove_attribute("agent");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttAgentident::WriteAgentident(pugi::xml_node element)
{
    bool wroteAttribute = false;
    if (this->HasAgent()) {
        element.append_attribute("agent") = StrToStr(this->GetAgent()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttAgentident::HasAgent() const
{
    return (m_agent != "");
}

/* include <attagent> */

//----------------------------------------------------------------------------
// AttEvidence
//----------------------------------------------------------------------------

AttEvidence::AttEvidence() : Att()
{
    ResetEvidence();
}

AttEvidence::~AttEvidence()
{
}

void AttEvidence::ResetEvidence()
{
    m_cert = CERTAINTY_NONE;
    m_evidence = "";
}

bool AttEvidence::ReadEvidence(pugi::xml_node element)
{
    bool hasAttribute = false;
    if (element.attribute("cert")) {
        this->SetCert(StrToCertainty(element.attribute("cert").value()));
        element.remove_attribute("cert");
        hasAttribute = true;
    }
    if (element.attribute("evidence")) {
        this->SetEvidence(StrToStr(element.attribute("evidence").value()));
        element.remove_attribute("evidence");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttEvidence::WriteEvidence(pugi::xml_node element)
{
    bool wroteAttribute = false;
    if (this->HasCert()) {
        element.append_attribute("cert") = CertaintyToStr(this->GetCert()).c_str();
        wroteAttribute = true;
    }
    if (this->HasEvidence()) {
        element.append_attribute("evidence") = StrToStr(this->GetEvidence()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttEvidence::HasCert() const
{
    return (m_cert != CERTAINTY_NONE);
}

bool AttEvidence::HasEvidence() const
{
    return (m_evidence != "");
}

/* include <attevidence> */

//----------------------------------------------------------------------------
// AttExtent
//----------------------------------------------------------------------------

AttExtent::AttExtent() : Att()
{
    ResetExtent();
}

AttExtent::~AttExtent()
{
}

void AttExtent::ResetExtent()
{
    m_extent = "";
}

bool AttExtent::ReadExtent(pugi::xml_node element)
{
    bool hasAttribute = false;
    if (element.attribute("extent")) {
        this->SetExtent(StrToStr(element.attribute("extent").value()));
        element.remove_attribute("extent");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttExtent::WriteExtent(pugi::xml_node element)
{
    bool wroteAttribute = false;
    if (this->HasExtent()) {
        element.append_attribute("extent") = StrToStr(this->GetExtent()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttExtent::HasExtent() const
{
    return (m_extent != "");
}

/* include <attextent> */

//----------------------------------------------------------------------------
// AttReasonident
//----------------------------------------------------------------------------

AttReasonident::AttReasonident() : Att()
{
    ResetReasonident();
}

AttReasonident::~AttReasonident()
{
}

void AttReasonident::ResetReasonident()
{
    m_reason = "";
}

bool AttReasonident::ReadReasonident(pugi::xml_node element)
{
    bool hasAttribute = false;
    if (element.attribute("reason")) {
        this->SetReason(StrToStr(element.attribute("reason").value()));
        element.remove_attribute("reason");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttReasonident::WriteReasonident(pugi::xml_node element)
{
    bool wroteAttribute = false;
    if (this->HasReason()) {
        element.append_attribute("reason") = StrToStr(this->GetReason()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttReasonident::HasReason() const
{
    return (m_reason != "");
}

/* include <attreason> */

bool Att::SetEdittrans(Object *element, std::string attrType, std::string attrValue)
{
    if (element->HasAttClass(ATT_AGENTIDENT)) {
        AttAgentident *att = dynamic_cast<AttAgentident *>(element);
        assert(att);
        if (attrType == "agent") {
            att->SetAgent(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass(ATT_EVIDENCE)) {
        AttEvidence *att = dynamic_cast<AttEvidence *>(element);
        assert(att);
        if (attrType == "cert") {
            att->SetCert(att->StrToCertainty(attrValue));
            return true;
        }
        if (attrType == "evidence") {
            att->SetEvidence(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass(ATT_EXTENT)) {
        AttExtent *att = dynamic_cast<AttExtent *>(element);
        assert(att);
        if (attrType == "extent") {
            att->SetExtent(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass(ATT_REASONIDENT)) {
        AttReasonident *att = dynamic_cast<AttReasonident *>(element);
        assert(att);
        if (attrType == "reason") {
            att->SetReason(att->StrToStr(attrValue));
            return true;
        }
    }

    return false;
}

void Att::GetEdittrans(const Object *element, ArrayOfStrAttr *attributes)
{
    if (element->HasAttClass(ATT_AGENTIDENT)) {
        const AttAgentident *att = dynamic_cast<const AttAgentident *>(element);
        assert(att);
        if (att->HasAgent()) {
            attributes->push_back(std::make_pair("agent", att->StrToStr(att->GetAgent())));
        }
    }
    if (element->HasAttClass(ATT_EVIDENCE)) {
        const AttEvidence *att = dynamic_cast<const AttEvidence *>(element);
        assert(att);
        if (att->HasCert()) {
            attributes->push_back(std::make_pair("cert", att->CertaintyToStr(att->GetCert())));
        }
        if (att->HasEvidence()) {
            attributes->push_back(std::make_pair("evidence", att->StrToStr(att->GetEvidence())));
        }
    }
    if (element->HasAttClass(ATT_EXTENT)) {
        const AttExtent *att = dynamic_cast<const AttExtent *>(element);
        assert(att);
        if (att->HasExtent()) {
            attributes->push_back(std::make_pair("extent", att->StrToStr(att->GetExtent())));
        }
    }
    if (element->HasAttClass(ATT_REASONIDENT)) {
        const AttReasonident *att = dynamic_cast<const AttReasonident *>(element);
        assert(att);
        if (att->HasReason()) {
            attributes->push_back(std::make_pair("reason", att->StrToStr(att->GetReason())));
        }
    }
}

} // vrv namespace
