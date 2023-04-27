/*
  ==============================================================================

	This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MultibandedDistortionPluginAudioProcessorEditor::MultibandedDistortionPluginAudioProcessorEditor(MultibandedDistortionPluginAudioProcessor& p)
	: AudioProcessorEditor(&p), audioProcessor(p),
	gainSliderAttachment(audioProcessor.apvts, "Peak Gain", gainSlider)
{
	// Make sure that before the constructor has finished, you've set the
	// editor's size to whatever you need it to be.
	for (auto comp:getComps())
	{
		addAndMakeVisible(comp);
	}
	setSize(600, 400);
}

MultibandedDistortionPluginAudioProcessorEditor::~MultibandedDistortionPluginAudioProcessorEditor()
{
}

//==============================================================================
void MultibandedDistortionPluginAudioProcessorEditor::paint(juce::Graphics& g)
{
	// (Our component is opaque, so we must completely fill the background with a solid colour)
	g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

	g.setColour(juce::Colours::white);
	g.setFont(15.0f);
	
}

void MultibandedDistortionPluginAudioProcessorEditor::resized()
{
	// This is generally where you'll want to lay out the positions of any
	// subcomponents in your editor..
	auto bounds = getLocalBounds();
	auto responseArea = bounds.removeFromTop(bounds.getHeight() * 0.66);

	auto knobsArea = bounds.removeFromLeft(bounds.getWidth() * 0.142);
	gainSlider.setBounds(knobsArea);
}

std::vector<juce::Component*> MultibandedDistortionPluginAudioProcessorEditor::getComps()
{
	return
	{
	&gainSlider 
	};
}