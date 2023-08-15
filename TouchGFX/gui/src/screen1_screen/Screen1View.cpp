#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/common/Constants.hpp>
#include <texts/TextKeysAndLanguages.hpp>
// #include <BitmapDatabase.hpp>
// #define BITMAP_SWIPE_PAGEINDICATOR_NORMAL_ID 0x0001
// #define BITMAP_SWIPE_PAGEINDICATOR_HIGHLIGHT_ID 0x0002
// 

Screen1View::Screen1View() : qrCode(nullptr)
{
	qrCode = new QRCode(QRCode::encodeText("", qrcodegen::QRCode::Ecc::LOW));
	swipeContainer.setPosition(0, 0, HAL::DISPLAY_WIDTH, HAL::DISPLAY_HEIGHT);
    swipeContainer.setSwipeDirection(DualSwipeContainer::VERTICAL);
    swipeContainer.setSwipeCutoff(50);
    swipeContainer.setEndSwipeElasticDistance(50);
    // swipeContainer.setPageIndicatorBitmaps(touchgfx::Bitmap(BITMAP_SWIPE_PAGEINDICATOR_NORMAL_ID),
    //                                        touchgfx::Bitmap(BITMAP_SWIPE_PAGEINDICATOR_HIGHLIGHT_ID));
    swipeContainer.setPageIndicatorXYWithCenteredCoordinate(HAL::DISPLAY_WIDTH - 25,
                                                            divBY2(HAL::DISPLAY_HEIGHT));
	add(swipeContainer);
	qrcodeContainer.setPosition(0, 0, HAL::DISPLAY_WIDTH, HAL::DISPLAY_HEIGHT);
	swipeContainer.add(qrcodeContainer);
	qrcodeTextArea.setPosition(GENERIC_PADDING,
                               TITLE_POS_Y,
                               HAL::DISPLAY_WIDTH - mulBY2(GENERIC_PADDING),
                               TITLE_HEIGHT);
    qrcodeTextArea.setColor(C_WHITE);
    qrcodeTextArea.setLinespacing(0);
    qrcodeTextArea.setTypedText(touchgfx::TypedText());
	qrCodeWidget.setQRCode(qrCode);
    qrCodeWidget.setScale(QRCODE_WIDTH / qrCode->getSize());
    qrCodeWidget.setXY(ALIGN_CENTER_HORIZONTAL_ON_SCREEN(qrCodeWidget), ALIGN_CENTER_VERTICAL_ON_SCREEN(qrCodeWidget));

    qrcodeContainer.add(qrcodeTextArea);
    qrcodeContainer.add(qrCodeWidget);
}
void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
	// qrCode = new QRCode(QRCode::encodeText("", qrcodegen::QRCode::Ecc::LOW));
}

void Screen1View::tearDownScreen()
{
	if (qrCode)
    {
        delete qrCode;
        qrCode = nullptr;
    }
    Screen1ViewBase::tearDownScreen();

}
void Screen1View::initializeQRCode()
{
    // qrCode = QRCode::encodeText("Hello QRCode 2!");
}
//void generateQRCodeImage(const char* data, const char* filename) {
//	qrcodegen::QrCode qrcode = qrcodegen::QrCode::encodeText("HELLO WORLD!", qrcodegen::QrCode::Ecc::MEDIUM);
//
//	std::vector<uint8_t> image;
//	for (int y = 0; y < qrcode.getSize(); y++) {
//		for (int x = 0; x < qrcode.getSize(); x++) {
//			// Convert QR code module to grayscale pixel (0: black, 255: white)
//			image.push_back(qrcode.getModule(x, y) ? 255 : 0);
//		}
//	}
//
//	// Encode and save the image using lodepng
//	unsigned error = lodepng::encode(filename, image.data(), qrcode.getSize(), qrcode.getSize());
//	if (error) {
//		std::cerr << "PNG encoding error: " << lodepng_error_text(error) << std::endl;
//	}
//}
//void Screen1View::function1(){
//	std::cout << "TRIGGER." << std::endl;
//	// const char* data = "HELLO WORLD!";
//	// const char* filename = "assets/images/qrcode.png"; // Adjust the path accordingly
//
////	generateQRCodeImage(data, filename);
//	std::cout << "QR code generation completed." << std::endl;
//}
