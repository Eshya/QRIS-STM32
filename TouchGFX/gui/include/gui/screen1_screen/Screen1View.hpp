#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <gui/containers/DualSwipeContainer.hpp>
#include <gui/widgets/QRCodeWidget.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <gui/model/QRCodeLM.h>
// using namespace qrcodegen;
class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void initializeQRCode();
    virtual void updateText();
    virtual void showqr();
    void createText(const char* newText);
protected:
    DualSwipeContainer swipeContainer;
    Container qrcodeContainer;
    TextArea qrcodeTextArea;
    QRCodeWidget qrCodeWidget;
    qrcodegen::QRCode* qrCode2 = nullptr;
    // QRCodeLM* qrCode = nullptr;
    uint16_t counter = 1111;
};

#endif // SCREEN1VIEW_HPP
