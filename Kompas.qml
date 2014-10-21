import QtQuick 1.1

Item {
    id: display
    property real value: 0
    property real fractPart: 0
    property real savedCourse: 0
    property real savedCourseVisibility: 0
    property real lastAngle: 0
    y: 10
    width: 720
    height: 720
        Image
        {
                x: 40
                y: 43
                width: 720
                height: 720
                z: 0
                rotation: 0
                clip: true
                sourceSize.height: 430
                sourceSize.width: 430
                anchors.verticalCenterOffset: -5
                anchors.horizontalCenterOffset: -6
                source: "content/kompasD1(720).png"
                smooth: true
                anchors.horizontalCenter: image1.horizontalCenter
                anchors.verticalCenter: image1.verticalCenter
                transform: Rotation
                {
                    id: needleSmallRotation
                    origin.x: 365
                    origin.y: 366
                    axis { x: 0; y: 0; z: 1 }
                    angle: -display.fractPart*3.6
                    Behavior on angle
                    {
                        SpringAnimation
                        {
                            spring: 1.4
                            damping: 0.5
                        }
                    }
                 }

            MouseArea
            {
                anchors.fill: parent
                id: kompasDMoueArea
                x: 0
                y: 3
                width: 100
                anchors.rightMargin: 0
                anchors.bottomMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0
                z: 1
                visible: true
                opacity: 1
                onClicked: _kompas.saveCourse()
            }
        }

        Image
        {
            id: smallNeedle
            x: 360
            width: 4
            height: 141
            anchors.horizontalCenterOffset: 0
            anchors.top: parent.top
            anchors.topMargin: 22
            anchors.horizontalCenter: image1.horizontalCenter
            z: 2
            clip: false
            fillMode: Image.PreserveAspectFit
            transformOrigin: Item.Center
            sourceSize.height: 480
            sourceSize.width: 480
            source: "content/needleSmall.png"
        }

        Image {
            id: image1
            x: -10
            y: -18
            width: 740
            height: 740
            //clip: true
            //sourceSize.width: 496
            z: -1
            source: "content/kompas(background).png"
            sourceSize.width: parent.width
            sourceSize.height: parent.height
        }

        Image {
            id: image2
            x: 1
            y: -8
            anchors.horizontalCenter: image1.horizontalCenter
            anchors.verticalCenter: image1.verticalCenter
            source: "content/kompas1(720).png"
            transform: Rotation
            {
                //id: needleSmallRotation
                origin.x: 360
                origin.y: 360
                axis { x: 0; y: 0; z: 1 }
                angle: -display.value
                Behavior on angle
                {
                    SpringAnimation
                    {
                        spring: 1.4
                        damping: 0.5
                    }
                }
             }
        }
}
