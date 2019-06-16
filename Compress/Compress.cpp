#include <iostream>
#include "dcmtk/dcmjpeg/djdecode.h"
#include "dcmtk/dcmjpeg/djencode.h"
#include "dcmtk/dcmdata/dcfilefo.h"
#include "dcmtk/dcmdata/dcdatset.h"
#include "dcmtk/dcmdata/dcitem.h"
#include "dcmtk/dcmjpeg/djrplol.h"
#include "dcmtk/dcmdata/dctk.h"

int main()
{
	DJEncoderRegistration::registerCodecs(); // register JPEG codecs
	DcmFileFormat fileformat;
	if (fileformat.loadFile("..\\..\\..\\test.dcm").good())
	{
		DcmDataset* dataset = fileformat.getDataset();
		DcmItem * metaInfo = fileformat.getMetaInfo();
		DJ_RPLossless params; // codec parameters, we use the defaults

		// this causes the lossless JPEG version of the dataset to be created
		if (dataset->chooseRepresentation(EXS_JPEGProcess14SV1, &params).good() &&
			dataset->canWriteXfer(EXS_JPEGProcess14SV1))
			{
				// force the meta-header UIDs to be re-generated when storing the file
				// since the UIDs in the data set may have changed
				delete metaInfo->remove(DCM_MediaStorageSOPClassUID);
				delete metaInfo->remove(DCM_MediaStorageSOPInstanceUID);

				// store in lossless JPEG format
				fileformat.saveFile("..\\..\\test_Encodejpeg.dcm", EXS_JPEGProcess14SV1);
			}
	}
	DJEncoderRegistration::cleanup(); // deregister JPEG codecs
}