/////////////////////////////////////////////////////////////////////////////
// Name:        layer.h
// Author:      Laurent Pugin
// Created:     2011
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#ifndef __VRV_LAYER_H__
#define __VRV_LAYER_H__

#include "atts_shared.h"
#include "drawinginterface.h"
#include "object.h"

namespace vrv {

class Clef;
class DeviceContext;
class LayerElement;
class Note;
class StaffDef;

//----------------------------------------------------------------------------
// Layer
//----------------------------------------------------------------------------

/**
 * This class represents a layer in a laid-out score (Doc).
 * A Layer is contained in a Staff.
 * It contains LayerElement objects.
*/
class Layer : public Object, public DrawingListInterface, public ObjectListInterface, public AttCommon {
public:
    /**
     * @name Constructors, destructors, and other standard methods
     * Reset method resets all attribute classes
     */
    ///@{
    Layer();
    virtual ~Layer();
    virtual void Reset();
    virtual std::string GetClassName() const { return "Layer"; };
    virtual ClassId Is() const { return LAYER; };
    ///@}

    /**
     * @name Methods for adding allowed content
     */
    ///@{
    virtual void AddChild(Object *object);
    ///@}

    /**
     * Return the index position of the layer in its staff parent.
     * The index position is 0-based.
     */
    int GetLayerIdx() const { return Object::GetIdx(); };

    LayerElement *GetPrevious(LayerElement *element);
    LayerElement *GetAtPos(int x);
    LayerElement *Insert(LayerElement *element, int x); // return a pointer to the inserted element

    /**
     * Get the current clef for the test element.
     * Goes back on the layer until a clef is found.
     * This is used when inserting a note by passing a y position because we need
     * to know the clef in order to get the pitch.
     */
    Clef *GetClef(LayerElement *test);

    /**
     * Return the clef offset for the position x.
     * The method uses Layer::GetClef first to find the clef before test.
     */
    int GetClefOffset(LayerElement *test);

    /**
     * @name Set and get the stem direction of the layer.
     * This stays STEMDIRECTION_NONE with on single layer in the staff.
     */
    ///@{
    void SetDrawingStemDir(data_STEMDIRECTION stemDirection) { m_drawingStemDir = stemDirection; };
    data_STEMDIRECTION GetDrawingStemDir() const { return m_drawingStemDir; };
    ///@}

    Clef *GetCurrentClef() const;
    KeySig *GetCurrentKeySig() const;
    Mensur *GetCurrentMensur() const;
    MeterSig *GetCurrentMeterSig() const;

    void ResetStaffDefOjects();

    /**
     * Set drawing clef, keysig and mensur if necessary and if available.
     */
    void SetDrawingAndCurrentValues(StaffDef *currentStaffDef);

    bool DrawKeySigCancellation() const { return m_drawKeySigCancellation; };
    void SetDrawKeySigCancellation(bool drawKeySigCancellation) { m_drawKeySigCancellation = drawKeySigCancellation; };
    Clef *GetStaffDefClef() { return m_staffDefClef; };
    KeySig *GetStaffDefKeySig() { return m_staffDefKeySig; };
    Mensur *GetStaffDefMensur() { return m_staffDefMensur; };
    MeterSig *GetStaffDefMeterSig() { return m_staffDefMeterSig; };

    //----------//
    // Functors //
    //----------//

    /**
     * See Object::UnsetCurrentScoreDef
     */
    virtual int UnsetCurrentScoreDef(FunctorParams *functorParams);

    /**
     * See Object::AlignHorizontally
     */
    virtual int AlignHorizontally(FunctorParams *functorParams);

    /**
     * See Object::AlignHorizontallyEnd
     */
    virtual int AlignHorizontallyEnd(FunctorParams *functorParams);

    /**
     * See Object::PrepareProcessingLists
     */
    virtual int PrepareProcessingLists(FunctorParams *functorParams);

    /**
     * See Object::SetDrawingXY
     */
    virtual int SetDrawingXY(FunctorParams *functorParams);

    /**
     * See Object::PrepareRpt
     */
    virtual int PrepareRpt(FunctorParams *functorParams);

    /**
     * See Object::CalcMaxMeasureDuration
     */
    virtual int CalcMaxMeasureDuration(FunctorParams *functorParams);

private:
    //
public:
    //
private:
    /**
     *
     */
    data_STEMDIRECTION m_drawingStemDir;

    /** */
    Clef *m_staffDefClef;
    KeySig *m_staffDefKeySig;
    Mensur *m_staffDefMensur;
    MeterSig *m_staffDefMeterSig;
    bool m_drawKeySigCancellation;
};

} // namespace vrv

#endif
