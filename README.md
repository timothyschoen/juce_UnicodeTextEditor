# juce_UnicodeTextEditor
A unicode text editor module for JUCE. Based on the original JUCE text editor, except it draws the text with an AttributedString. So far, it has behaved the same as the regular JUCE TextEditor for me, except that non-latin characters will render correctly.

Please let me know if you experience any problems!

You can override the fillTextEditorBackground, drawTextEditorOutline and createCaretComponent functions to do custom background/outline/caret drawing.

<img width="865" alt="Screenshot 2022-10-28 at 00 41 20" src="https://user-images.githubusercontent.com/44585538/198411457-d24495f8-5198-49f0-9dee-ddf844f012ac.png">
