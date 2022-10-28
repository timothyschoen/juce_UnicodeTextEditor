#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);
    addAndMakeVisible(unicodeEditor);
    unicodeEditor.setMultiLine(true);
    unicodeEditor.setReturnKeyStartsNewLine(true);
    
    normalEditor.setMultiLine(true);
    normalEditor.setReturnKeyStartsNewLine(true);
    addChildComponent(normalEditor);
    
    toggleEditorButton.setButtonText("Disable Unicode");
    toggleEditorButton.setToggleState(true, juce::dontSendNotification);
    addAndMakeVisible(&toggleEditorButton);
    toggleEditorButton.setConnectedEdges(12);
    toggleEditorButton.setClickingTogglesState(true);
    
    toggleEditorButton.onClick = [this](){
        auto state = toggleEditorButton.getToggleState();
        normalEditor.setVisible(!state);
        unicodeEditor.setVisible(state);
        
        toggleEditorButton.setButtonText(state ? "Disable Unicode" : "Enable Unicode");
        
        if(state) {
            unicodeEditor.setText(normalEditor.getText());
        }
        else {
            normalEditor.setText(unicodeEditor.getText());
        }
    };
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    unicodeEditor.setBounds(getLocalBounds());
    normalEditor.setBounds(getLocalBounds());
    
    toggleEditorButton.setBounds(0, getHeight() - 30, 100, 30);
}
