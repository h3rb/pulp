#pragma once

/*
 * An ASCII image class, which includes everything
 * to write to such a thing.
 *
 * This class is also used as an "off-screen buffer"
 */

class AImage {
public:
 Indexed<APixel> buffer;
 void Circle( int x, int y, int R, APixel *brush ) {
 }
 void Line( int x, int y, int x2, int y2, APixel *brush ) {
 }
 void HLine( int x, int y, int x2, APixel *brush ) {
 }
 void VLine( int x, int y, int y2, APixel *brush ) {
 }
};
