#include <iostream>
#include <fstream>
#include <string>
#include "dcmtk/dcmdata/libi2d/i2dimgs.h"
#include "dcmtk/dcmdata/dcdatset.h"
#include "dcmtk/dcmdata/libi2d/i2doutpl.h"
#include "dcmtk/dcmdata/libi2d/i2d.h"
#include "dcmtk/dcmdata/dctk.h"
#include "dcmtk/dcmimgle/dcmimage.h"
#include "dcmtk/dcmdata/libi2d/i2djpgs.h"
#include "dcmtk/dcmdata/libi2d/i2dplsc.h"


unsigned char* readBMP(char * filename) {
	int i;
	FILE* f = fopen(filename, "rb");
	unsigned char info[54];
	fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

	// extract image height and width from header
	int width = *(int*)& info[18];
	int height = *(int*)& info[22];

	int size = 3 * width * height;
	unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
	fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once
	fclose(f);

	for (i = 0; i < size; i += 3)
	{
		unsigned char tmp = data[i];
		data[i] = data[i + 2];
		data[i + 2] = tmp;
	}

	return data;
}

int main() {
	DcmDataset* dataset = NULL;
	

	
	//Uint8* image = readBMP("..\\..\\..\\lena.jpg");
	//for (int i = 0; i < 512 * 512; i++) {
	//	image[i] = 255;
	//}
	

	//std::cout << "hi";
	Image2Dcm i2d;
	E_TransferSyntax proposedTS;
	I2DJpegSource* i2dinplug = new I2DJpegSource();
	
	i2dinplug->setImageFile("..\\..\\..\\lena.jpg");

	I2DOutputPlug* i2doutplug = new I2DOutputPlugSC();
	
	i2d.convert(i2dinplug, i2doutplug, dataset, proposedTS);
	
	/*
	
	std::cout << "hi";
	Uint16 rows;
	Uint16 cols;
	Uint16 samplesPerPixel;
	OFString photoMetrInt;
	Uint16 bitsAlloc;
	Uint16 bitsStored;
	Uint16 highBit;
	Uint16 pixelRepr;
	Uint16 planConf;
	Uint16 pixAspectH;
	Uint16 pixAspectV;
	char* pixData;
	Uint32 length;
	E_TransferSyntax ts;
	OFBool srcEncodingLossy;
	OFString srcLossyComprMethod;


	OFCondition ofimage = i2dimg->readPixelData(rows, cols, samplesPerPixel, photoMetrInt, bitsAlloc, bitsStored, highBit, pixelRepr, planConf, pixAspectH, pixAspectV, pixData, length, ts);

	i2dimg->getLossyComprInfo(srcEncodingLossy, srcLossyComprMethod);

	//Uint8* image = (Uint8 *)pixData;
	//std::cout << (int)*(image);

	dataset->putAndInsertString(DCM_SamplesPerPixel, std::to_string(samplesPerPixel).c_str());
	dataset->putAndInsertString(DCM_BitsStored, std::to_string(bitsStored).c_str());
	dataset->putAndInsertString(DCM_PhotometricInterpretation, "RGB");
	dataset->putAndInsertString(DCM_PixelRepresentation, std::to_string(pixelRepr).c_str());
	dataset->putAndInsertString(DCM_BitsAllocated, std::to_string(bitsAlloc).c_str());
	dataset->putAndInsertString(DCM_HighBit, std::to_string(highBit).c_str());
	dataset->putAndInsertString(DCM_PlanarConfiguration, std::to_string(planConf).c_str());
	//dataset->putAndInsertString(DCM_PixelAspectRatio, std::to_string(1).c_str());
	dataset->putAndInsertString(DCM_LossyImageCompression, "01");
	dataset->putAndInsertOFStringArray(DCM_LossyImageCompressionMethod, srcLossyComprMethod);
	//dataset->putAndInsertString(DCM_pixelAs)
	//dataset->putAndInsertString(DCM_WindowCenter, "500");
	//dataset->putAndInsertString(DCM_WindowWidth, "4000");

	dataset->putAndInsertString(DCM_Rows, std::to_string(rows).c_str());
	dataset->putAndInsertString(DCM_Columns, std::to_string(cols).c_str());

	dataset->putAndInsertUint8Array(DCM_PixelData, (Uint8*) pixData, rows*cols);

	//dataset->putAndInsertString(DCM_ImplementationVersionName )

	//dataset->putAndInsertUint8Array(DCM_PixelData, image, 1);
	
	//DicomImage* image = new DicomImage("..\\..\\..\\test.dcm");
	//image->writeImageToDataset(*dataset);
	
	//std::cout << (int) pixAspectH << "  : image";
	std::cout << i2dimg->inputFormat();
	std::cout << "length : " << length << " rows x cols " << rows << " x " << cols << "\n";
	std::cout << ts;
	*/
	
	dataset->putAndInsertString(DCM_PatientName, "Lena");
	DcmFileFormat fileformat(dataset);
	fileformat.saveFile("..\\..\\newdicom.dcm", proposedTS);

}