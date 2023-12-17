// CO2 Stand

include <scad-text/scad_text.scad>


module stand(width=60, base_length=70, display_angle=40, display_thickness=4, stand_height=50) {
        union() {
                cube ([width, base_length, 15]);
                cube ([width, display_thickness, stand_height]);
                inset_y = cos (90 - display_angle) * display_thickness;
                inset_z = sin(90 - display_angle) * display_thickness;
                translate([0,inset_y, stand_height-inset_z])rotate([display_angle, 0,0])
                display_plate(width, 40, display_thickness);
        }
                
}

module stand_with_text() {
        difference() {
                stand();
                translate([30,0,20])writeText(0,0,0, "CO₂", size=6);
        }
}

// display_plate represents a mounting plate for the 128x64 OLED featherwing display, with
// details here: https://learn.adafruit.com/assets/94579
module display_plate(width=60, height=40, thickness=5) {
        hole_r = 2.5;
        difference() {
                cube([width, height, thickness]);
                translate([(width-45.72 - (2*hole_r))/2, (height - 17.78 - (2*hole_r))/2, 0])display_holes(thickness+1, hole_r);
        }
}


module display_holes(thickness=6, r=3) {
        $fn=100;
        offset = r;
        translate([offset, offset, 0])cylinder(r=r, h=thickness);
        translate([45.72 + offset, offset, 0])cylinder(r=r, h=thickness);
        translate([offset, 17.78+offset, 0])cylinder(r=r, h=thickness);
        translate([45.72 + offset, 17.78 + offset, 0])cylinder(r=r, h=thickness);
}


stand_with_text();