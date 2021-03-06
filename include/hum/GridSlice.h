//
// Programmer:    Craig Stuart Sapp <craig@ccrma.stanford.edu>
// Creation Date: Sun Oct 16 16:08:05 PDT 2016
// Last Modified: Sun Oct 16 16:08:08 PDT 2016
// Filename:      GridSlice.h
// URL:           https://github.com/craigsapp/hum2ly/blob/master/include/GridSlice.h
// Syntax:        C++11
// vim:           ts=3 noexpandtab
//
// Description:   HumGrid is an intermediate container for converting from
//                MusicXML syntax into Humdrum syntax. GridSlice is a
//                time instance which contains all notes in all parts
//                that should be played at that time.
//

#ifndef _GRIDSLICE_H
#define _GRIDSLICE_H

#include "humlib.h"
#include "grid.h"
#include "MxmlPart.h"
#include "GridPart.h"
#include "GridMeasure.h"

#include <vector>
#include <list>

using namespace std;

namespace hum {


class HumGrid;


class GridSlice : public vector<GridPart*> {
	public:
		GridSlice(GridMeasure* measure, HumNum timestamp, SliceType type,
		          int partcount = 0);
		GridSlice(GridMeasure* measure, HumNum timestamp, SliceType type,
		          const GridSlice& slice);
		GridSlice(GridMeasure* measure, HumNum timestamp, SliceType type,
		          GridSlice* slice);
		~GridSlice();

		bool isNoteSlice(void)     { return m_type == SliceType::Notes; }
		bool isGraceSlice(void)    { return m_type == SliceType::GraceNotes; }
		bool isMeasureSlice(void)  { return m_type == SliceType::Measures; }
		bool isClefSlice(void)     { return m_type == SliceType::Clefs; }
		bool isTimeSigSlice(void)  { return m_type == SliceType::TimeSigs; }
		bool isMeterSigSlice(void) { return m_type == SliceType::MeterSigs; }
		bool isManipulatorSlice(void) { return m_type==SliceType::Manipulators; }
		bool isInvalidSlice(void)  { return m_type == SliceType::Invalid; }
		bool isInterpretationSlice(void);
		bool isDataSlice(void);
		SliceType getType(void)    { return m_type; }

		void transferTokens    (HumdrumFile& outfile, bool recip);
		void initializePartStaves (vector<MxmlPart>& partdata);

		HumNum       getDuration        (void);
		void         setDuration        (HumNum duration);
		HumNum       getTimestamp       (void);
		void         setTimestamp       (HumNum timestamp);
		void         setOwner           (HumGrid* owner);
		HumGrid*     getOwner           (void);
		HumNum       getMeasureDuration (void);
		HumNum       getMeasureTimestamp(void);
		GridMeasure* getMeasure         (void);
		void         invalidate         (void);

		void transferSides        (HumdrumLine& line, GridStaff& sides, 
		                           const string& empty, int maxvcount,
		                           int maxhcount);
		void transferSides        (HumdrumLine& line, GridPart& sides, 
		                           const string& empty, int maxvcount,
		                           int maxhcount);
		int getVerseCount         (int partindex, int staffindex);
		int getHarmonyCount       (int partindex, int staffindex = -1);

	protected:
		HTp  createRecipTokenFromDuration  (HumNum duration);

	private:
		HumGrid*     m_owner;
		GridMeasure* m_measure;
		HumNum       m_timestamp;
		HumNum       m_duration;
		SliceType    m_type;

};


ostream& operator<<(ostream& output, GridSlice* slice);


} // end namespace hum

#endif /* _GRIDSLICE_H */



