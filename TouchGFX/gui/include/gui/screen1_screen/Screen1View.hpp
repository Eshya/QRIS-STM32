#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <gui/containers/DualSwipeContainer.hpp>
#include <gui/widgets/QRCodeWidget.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/TextArea.hpp>
class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void initializeQRCode();
protected:
    DualSwipeContainer swipeContainer;
    Container qrcodeContainer;
    TextArea qrcodeTextArea;
    QRCodeWidget qrCodeWidget;
    QRCode* qrCode;
};

#endif // SCREEN1VIEW_HPP
