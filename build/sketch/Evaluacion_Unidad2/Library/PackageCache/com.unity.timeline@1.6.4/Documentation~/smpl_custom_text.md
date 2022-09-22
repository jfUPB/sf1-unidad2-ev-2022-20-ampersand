#line 1 "/home/pop-os/sf1-unidad2-ev-2022-20-ampersand/Evaluacion_Unidad2/Library/PackageCache/com.unity.timeline@1.6.4/Documentation~/smpl_custom_text.md"
# Text Track sample

_This track requires the TextMeshPro package to be installed in the project._

This type of track can be used to display different messages to the screen using a TextMeshPro Text Component. It is ideal for things like subtitles. It demonstrates the following:

* Registering custom previewable properties in a custom track.
* Perform custom blending of clips using a mixer PlayableBehaviour.
* Provide custom clip data that can be animated using the inline curve editor using a PlayableBehaviour template.
* Using a ClipEditor to react to changes in a clip.

## Usage

To use this custom track, drag a TextMeshPro Text Component into the hierarchy view of the Timeline. A TextTrack will be created, and use the track context menu to create clips. Clip properties such as Message, FontSize and Color can be modified in the inspector by selecting the clip. Clips can be overlapped to create transitions.
