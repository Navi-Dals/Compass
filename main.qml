import QtQuick 1.1
import QtQuick 1.0

Rectangle {
    id: rectangle1
    //width:  window.dwidth
    //height: window.dheight
    width:  1280
    height: 800
    //color: "#D3D3D3"
    color : "#000000"
    gradient: Gradient { // добавление градиента
        GradientStop {
            id: gradient0
            position: 0.0
            color: "#000000"
        }
        GradientStop {
            id: gradient1
            position: 0.2
            color: "#363636"
        }
        GradientStop {
            id: gradient2
            position: 0.4
            color: "#828282"
        }
        GradientStop {
            id: gradient3
            position: 0.6
            color: "#696969"
        }
        GradientStop {
            id: gradient4
            position: 0.8
            color: "#363636"
        }
        GradientStop {
            id: gradient5
            position: 1
            color: "#1C1C1C"
        }
    }

    property string gradientcolor0: "#FF7C7C7C"
    property string gradientcolor1: "#FF4E4E4E"
    Rectangle
    {
        id: buttonOn
        x: 34
        y:339
        width: 116
        height: 26
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 115
        anchors.left: parent.left
        anchors.leftMargin: 18
        visible: false
        Text {
            id: text2
            anchors.centerIn: parent;
            text: "Старт"
            font.pixelSize: 15
            color: "#FFFFFF"
        }
        gradient: Gradient { // добавление градиента
            GradientStop {
                id: bongradient0
                position: 0
                color: rectangle1.gradientcolor0
            }
            GradientStop {
                id: bongradient1
                position: 1
                color: rectangle1.gradientcolor1
            }
        }
        ParallelAnimation {
            id: bonEnterAnim
            PropertyAnimation {
                target: bongradient0
                properties: "color"
                to: rectangle1.gradientcolor1
                duration: 300
            }
            PropertyAnimation {
                target: bongradient1
                properties: "color"
                to: rectangle1.gradientcolor0
                duration: 300
            }
        }
        ParallelAnimation {
            id: bonExitAnim
            PropertyAnimation {
                target: bongradient0
                properties: "color"
                to: rectangle1.gradientcolor0
                duration: 300
            }
            PropertyAnimation {
                target: bongradient1
                properties: "color"
                to: rectangle1.gradientcolor1
                duration: 300
            }
        }

        MouseArea
        {
            anchors.fill: parent
            id: mouseAreaOn
            visible: true
            opacity: 1
            hoverEnabled: true
            onEntered: bonEnterAnim.start()
            onExited: bonExitAnim.start()
            //При нажатии вызвать функцию
            onClicked: _kompas.startThread()
        }

    }
    Rectangle
    {
        id: buttonOff
        x: 34
        y:371
        width: 116
        height: 26
        visible: false
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 83
        anchors.left: parent.left
        anchors.leftMargin: 18
        Text {
            id: text3
            anchors.centerIn: parent;
            text: "Стоп"
            font.pixelSize: 15
            color: "#FFFFFF"
        }
        gradient: Gradient { // добавление градиента
            GradientStop {
                id: boffgradient0
                position: 0
                color: rectangle1.gradientcolor0
            }
            GradientStop {
                id: boffgradient1
                position: 1
                color: rectangle1.gradientcolor1
            }
        }
        ParallelAnimation {
            id: boffEnterAnim
            PropertyAnimation {
                target: boffgradient0
                properties: "color"
                to: rectangle1.gradientcolor1
                duration: 300
            }
            PropertyAnimation {
                target: boffgradient1
                properties: "color"
                to: rectangle1.gradientcolor0
                duration: 300
            }
        }
        ParallelAnimation {
            id: boffExitAnim
            PropertyAnimation {
                target: boffgradient0
                properties: "color"
                to: rectangle1.gradientcolor0
                duration: 300
            }
            PropertyAnimation {
                target: boffgradient1
                properties: "color"
                to: rectangle1.gradientcolor1
                duration: 300
            }
        }
        MouseArea
        {
            anchors.fill: parent
            id: mouseAreaOff
            hoverEnabled: true
            onEntered: boffEnterAnim.start()
            onExited: boffExitAnim.start()
            //При нажатии вызвать функцию
            onClicked: _kompas.quitThread()
        }

    }

    //компас
    Kompas
    {
        id:kompas
        x: 7
        y: 0
        width: 720
        height: 718
        anchors.verticalCenterOffset: 22
        anchors.horizontalCenterOffset: -43
        objectName: "kompas"
        anchors.centerIn: parent
        value:_kompas.angle
        fractPart:_kompas.fractPart
        savedCourse: _kompas.savedCourse
        savedCourseVisibility: _kompas.savedCourseVisibility
        lastAngle: _kompas.lastAngle

        //лсд дисплей
        Rectangle
        {
            id: lcdDisplay
            x: 155
            anchors.centerIn: parent
            border.width: 3
            border.color: "black"
            width: 177
            height: 75
            color: "#000000"
            anchors.verticalCenterOffset: -5
            anchors.horizontalCenterOffset: -10
            FontLoader { id: a_LCDNovaObl; source: "content/a_LCDNovaObl.ttf" }
            Text
            {
                id: lcdNumbers
                anchors.centerIn: parent
                text: _kompas.afterComma === 0 ? _kompas.fullangle%360+".0" : _kompas.fullangle%360
                font.pixelSize: 50
                font.family: a_LCDNovaObl.name
                style: Text.Outline
                styleColor: "blue"
                color: (_kompas.color === 0 ? "white" :( _kompas.color === 1 ? "blue":(_kompas.color === 2 ? "red":(_kompas.color=== 3 ? "green":"green"))))
            }
        }



    }
    Rectangle
    {
        id: connection_stateDisplay
        x: 34
        y: 113
        width: 125
        height: 37
        color: "#0b0a0a"
        visible: false
        border.width: 5
        border.color: "#616461"
        Text
        {
            id: connection_stateText
            anchors.centerIn: parent
            text: _kompas.connect_state==1 ? "ПОДКЛЮЧЕНО" :"НЕ ПОДКЛЮЧЕНО"
            //text: _kompas.state
            font.pixelSize: 13
            font.family: a_LCDNovaObl.name
            style: Text.Outline
            styleColor: "red"
            color: "red"
        }
        Text
        {
            y: -22
            width: 162
            height: 18
            text:"Статус подключения"
            font.pixelSize: 14
            font.family: a_LCDNovaObl.name
            color: "white";

        }

    }
    Rectangle
    {
        id: supplyDisplay;
        x: 34
        y: 46
        width: 125
        height: 37
        color: "#0b0a0a"
        visible: false
        border.width: 5
        border.color: "#616461"
        Text
        {
            id: supplyText
            anchors.centerIn: parent
            text: _kompas.supply==0 ? "СЕТЬ" :"АККУМУЛЯТОР"
            //text: _kompas.state
            font.pixelSize: _kompas.supply==0 ? 22 :15
            font.family: a_LCDNovaObl.name
            style: Text.Outline
            styleColor: "red"
            color: "red"
        }
        Text
        {
            x: 0
            y: -23
            width: 110
            height: 18
            text:"Режим работы"
            font.pixelSize: 14
            font.family: a_LCDNovaObl.name
            color: "white";
        }
    }
    Rectangle
    {
        id: connection
        x: 34
        y: 179
        width: 125
        height: 37
        color: "#0b0a0a"
        visible: false
        border.width: 5
        border.color: "#616561"
        Text
        {
            id: connectionText
            anchors.centerIn: parent
            text:(_kompas.Connect===0 ? "RS232" :(_kompas.Connect===1 ? "RS485" :(_kompas.Connect===2 ? "MIL-STD-1553":"NAN")))
            //text: _kompas.state
            font.pixelSize: _kompas.Connect===2 ? 15 :22
            font.family: a_LCDNovaObl.name
            style: Text.Outline
            styleColor: "red"
            color: "red"
        }
        Text
        {
            y: -22
            width: 162
            height: 18
            text:"Выбранный интерфейс"
            font.pixelSize: 14
            font.family: a_LCDNovaObl.name
            color: "white";

        }
    }
    Rectangle
    {
        id: menuButton
        x: 34
        y:187
        width: 135
        height: 37
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 576
        anchors.left: parent.left
        anchors.leftMargin: 1137
        visible: true
        Text {
            id: menuText
            anchors.centerIn: parent;
            text: "Настройки"
            font.pixelSize: 15
            color: "#FFFFFF"
        }
        gradient: Gradient { // добавление градиента
            GradientStop {
                id: bmenugradient0
                position: 0
                color: rectangle1.gradientcolor0
            }
            GradientStop {
                id: bmenugradient1
                position: 1
                color: rectangle1.gradientcolor1
            }
        }
        ParallelAnimation {
            id: bmenuEnterAnim
            PropertyAnimation {
                target: bmenugradient0
                properties: "color"
                to: rectangle1.gradientcolor1
                duration: 300
            }
            PropertyAnimation {
                target: bmenugradient1
                properties: "color"
                to: rectangle1.gradientcolor0
                duration: 300
            }
        }
        ParallelAnimation {
            id: bmenuExitAnim
            PropertyAnimation {
                target: bmenugradient0
                properties: "color"
                to: rectangle1.gradientcolor0
                duration: 300
            }
            PropertyAnimation {
                target: bmenugradient1
                properties: "color"
                to: rectangle1.gradientcolor1
                duration: 300
            }
        }
        MouseArea
        {
            anchors.fill: parent
            id: menuMouseArea
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.leftMargin: 1
            anchors.topMargin: 0
            visible: true
            opacity: 1
            hoverEnabled: true
            onEntered: bmenuEnterAnim.start()
            onExited: bmenuExitAnim.start()
            //При нажатии вызвать функцию
            onClicked: _kompas.showMenu()
        }

    }
    Rectangle
    {
        id: colorButton
        x: 657
        y: 46
        width: 135
        height: 44
        visible: false
        anchors.right: parent.right
        anchors.rightMargin: 8
        Text {
            id: colotText
            anchors.centerIn: parent;
            text: "Изменить цвет"
            font.pixelSize: 15
            color: "#FFFFFF"
        }
        gradient: Gradient { // добавление градиента
            GradientStop {
                id: bcolorgradient0
                position: 0
                color: "#ffffff"
            }
            GradientStop {
                id: bcolorgradient1
                position: 1
                color: rectangle1.gradientcolor1
            }
        }
        ParallelAnimation {
            id: bcolorEnterAnim
            PropertyAnimation {
                target: bcolorgradient0
                properties: "color"
                to: rectangle1.gradientcolor1
                duration: 300
            }
            PropertyAnimation {
                target: bcolorgradient1
                properties: "color"
                to: rectangle1.gradientcolor0
                duration: 300
            }
        }
        ParallelAnimation {
            id: bcolorExitAnim
            PropertyAnimation {
                target: bcolorgradient0
                properties: "color"
                to: rectangle1.gradientcolor0
                duration: 300
            }
            PropertyAnimation {
                target: bcolorgradient1
                properties: "color"
                to: rectangle1.gradientcolor1
                duration: 300
            }
        }
        MouseArea
        {
            anchors.fill: parent
            id: colorMouseArea
            hoverEnabled: true
            onEntered: bcolorEnterAnim.start()
            onExited: bcolorExitAnim.start()
            //При нажатии вызвать функцию
            onClicked: _kompas.changeColor()
        }
    }
    Rectangle
    {
        id: tmcButton
        x: 657
        y: 365
        width: 135
        height: 44
        visible: true
        anchors.right: parent.right
        anchors.rightMargin: 8
        Text {
            id: tmcText
            anchors.centerIn: parent
            text: _kompas.trueMagneticCourse === false ? "Tru Course":"Magnetic Course"
            font.pixelSize: 15
            color: "#FFFFFF"
        }
        gradient: Gradient { // добавление градиента
            GradientStop {
                id: tmcgradient0
                position: 0
                color: "#ffffff"
            }
            GradientStop {
                id: tmcgradient1
                position: 1
                color: rectangle1.gradientcolor1
            }
        }
        ParallelAnimation {
            id: tmcEnterAnim
            PropertyAnimation {
                target: tmcgradient0
                properties: "color"
                to: rectangle1.gradientcolor1
                duration: 300
            }
            PropertyAnimation {
                target: tmcgradient1
                properties: "color"
                to: rectangle1.gradientcolor0
                duration: 300
            }
        }
        ParallelAnimation {
            id: tmcExitAnim
            PropertyAnimation {
                target: tmcgradient0
                properties: "color"
                to: rectangle1.gradientcolor0
                duration: 300
            }
            PropertyAnimation {
                target: tmcgradient1
                properties: "color"
                to: rectangle1.gradientcolor1
                duration: 300
            }
        }
        MouseArea
        {
            anchors.fill: parent
            id: tmcMouseArea
            visible: true
            hoverEnabled: true
            onEntered: tmcEnterAnim.start()
            onExited: tmcExitAnim.start()
            //При нажатии вызвать функцию
            onClicked: _kompas.changeTrueMagneticCourse();
        }
    }
    Rectangle
    {
        id: pitch
        x: 18
        y: 63
        visible: _kompas.infoVisibility
        width: 114
        height: 44
        border.width: 2
        border.color: "#0500ff"
        color: "black"
        Text
        {
            id: pitchText
            x: 0
            y: -30
            text: "Дифферент"
            font.pixelSize: 22
            font.family: a_LCDNovaObl.name
            color: "white";
        }
        Text
        {
            id: pitchArg
            anchors.centerIn: parent
            text: _kompas.pitch
            font.pixelSize: 22
            font.family: a_LCDNovaObl.name
            style: Text.Outline
            styleColor: "white"
            color: "white";
        }
    }

//коэффициент А потенциометра
    Rectangle
    {
        id: potenA
        x: 8
        y: 340
        //visible: _kompas.infoVisibility
        width: 114
        height: 44
        border.width: 2
        border.color: "#0500ff"
        color: "black"
        Text
        {
            id: potenAText
            x: 0
            y: -30
            text: "коэффициент А"
            font.pixelSize: 22
            font.family: a_LCDNovaObl.name
            color: "white";
        }
        Text
        {
            id: potenAArg
            anchors.centerIn: parent
            text: _kompas.potenA()
            font.pixelSize: 22
            font.family: a_LCDNovaObl.name
            style: Text.Outline
            styleColor: "white"
            color: "white";
        }
    }

//коэффициент B потенциометра
    Rectangle
    {
        id: potenB
        x: 8
        y: 423
        //visible: _kompas.infoVisibility
        width: 114
        height: 44
        border.width: 2
        border.color: "#0500ff"
        color: "black"
        Text
        {
            id: potenBText
            x: 0
            y: -30
            text: "коэффициент B"
            font.pixelSize: 22
            font.family: a_LCDNovaObl.name
            color: "white";
        }
        Text
        {
            id: potenBArg
            anchors.centerIn: parent
            text: _kompas.poetB()
            font.pixelSize: 22
            font.family: a_LCDNovaObl.name
            style: Text.Outline
            styleColor: "white"
            color: "white";
        }
    }

//коэффициент C потенциометра
    Rectangle
    {
        id: potenC
        x: 8
        y: 518
        //visible: _kompas.infoVisibility
        width: 114
        height: 44
        border.width: 2
        border.color: "#0500ff"
        color: "black"
        Text
        {
            id: potenCText
            x: 0
            y: -30
            text: "коэффициент C"
            font.pixelSize: 22
            font.family: a_LCDNovaObl.name
            color: "white";
        }
        Text
        {
            id: potenCArg
            anchors.centerIn: parent
            text: _kompas.poetC()
            font.pixelSize: 22
            font.family: a_LCDNovaObl.name
            style: Text.Outline
            styleColor: "white"
            color: "white";
        }
    }

    Rectangle
    {
        id: roll
        x: 18
        y: 148
        visible: _kompas.infoVisibility
        width: 114
        height: 44
        border.width: 2
        border.color: "blue"
        color: "black"
        Text
        {
            id: rollText
            x: 0
            y: -29
            text: "Крен"
            font.pixelSize: 22
            font.family: a_LCDNovaObl.name
            color: "white";
        }
        Text
        {
            id: rollArg
            anchors.centerIn: parent
            text: _kompas.roll
            font.pixelSize: 22
            font.family: a_LCDNovaObl.name
            style: Text.Outline
            styleColor: "white"
            color: "white";
        }
    }
 //   coef_A
    Rectangle
    {
        id: aButton
        x: 1137
        y: 241
        width: 135
        height: 43
        visible: true
        anchors.right: parent.right
        anchors.rightMargin: 8
        Text {
            id:  aButtonText
            anchors.centerIn: parent;
            text: "Коэффициент А"
            font.pixelSize: 15
            color: "#FFFFFF"
        }
        gradient: Gradient { // добавление градиента
            GradientStop {
                id: bArgradient0
                position: 0
                color: rectangle1.gradientcolor0
            }
            GradientStop {
                id: bArgradient1
                position: 1
                color: rectangle1.gradientcolor1
            }
        }
        ParallelAnimation {
            id: bAEnterAnim
            PropertyAnimation {
                target: bArgradient0
                properties: "color"
                to: rectangle1.gradientcolor1
                duration: 300
            }
            PropertyAnimation {
                target: bArgradient1
                properties: "color"
                to: rectangle1.gradientcolor0
                duration: 300
            }
        }
        ParallelAnimation {
            id: bAExitAnim
            PropertyAnimation {
                target: bArgradient0
                properties: "color"
                to: rectangle1.gradientcolor0
                duration: 300
            }
            PropertyAnimation {
                target: bArgradient1
                properties: "color"
                to: rectangle1.gradientcolor1
                duration: 300
            }
        }
        MouseArea
        {
            anchors.fill: parent
            id:  aButtonMouseArea
            anchors.rightMargin: 0
            anchors.bottomMargin: -1
            anchors.leftMargin: 0
            anchors.topMargin: 1
            hoverEnabled: true
            onEntered: bAEnterAnim.start()
            onExited: bAExitAnim.start()
            //При нажатии вызвать функцию
            onClicked: _kompas.changeA()
        }
    }
    //демпфирование
       Rectangle
       {
           id: demButton
           x: 1137
           y: 305
           width: 135
           height: 43
           visible: true
           anchors.right: parent.right
           anchors.rightMargin: 8
           Text {
               id:  demButtonText
               anchors.centerIn: parent;
               text: "Демпфирование"
               font.pixelSize: 15
               color: "#FFFFFF"
           }
           gradient: Gradient { // добавление градиента
               GradientStop {
                   id: bDemrgradient0
                   position: 0
                   color: "#ffffff"
               }
               GradientStop {
                   id: bDemrgradient1
                   position: 1
                   color: rectangle1.gradientcolor1
               }
           }
           ParallelAnimation {
               id: bDemEnterAnim
               PropertyAnimation {
                   target: bDemrgradient0
                   properties: "color"
                   to: rectangle1.gradientcolor1
                   duration: 300
               }
               PropertyAnimation {
                   target: bDemrgradient1
                   properties: "color"
                   to: rectangle1.gradientcolor0
                   duration: 300
               }
           }
           ParallelAnimation {
               id: bDemExitAnim
               PropertyAnimation {
                   target: bDemrgradient0
                   properties: "color"
                   to: rectangle1.gradientcolor0
                   duration: 300
               }
               PropertyAnimation {
                   target: bDemrgradient1
                   properties: "color"
                   to: rectangle1.gradientcolor1
                   duration: 300
               }
           }
           MouseArea
           {
               anchors.fill: parent
               id:  demButtonMouseArea
               anchors.rightMargin: 0
               anchors.bottomMargin: -1
               anchors.leftMargin: 0
               anchors.topMargin: 1
               hoverEnabled: true
               onEntered: bDemEnterAnim.start()
               onExited: bDemExitAnim.start()
               //При нажатии вызвать функцию
               onClicked: _kompas.changeDempf()
           }
       }
    //sklonenie
    Rectangle
    {
        id: sklButton
        x: 657
        y: 47
        width: 135
        height: 43
        visible: true
        anchors.right: parent.right
        anchors.rightMargin: 8
        Text {
            id:  sklButtonText
            anchors.centerIn: parent;
            text: "Склонение"
            font.pixelSize: 15
            color: "#FFFFFF"
        }
        gradient: Gradient { // добавление градиента
            GradientStop {
                id: bsklrgradient0
                position: 0
                color: "#ffffff"
            }
            GradientStop {
                id: bsklrgradient1
                position: 1
                color: rectangle1.gradientcolor1
            }
        }
        ParallelAnimation {
            id: bsklEnterAnim
            PropertyAnimation {
                target: bsklrgradient0
                properties: "color"
                to: rectangle1.gradientcolor1
                duration: 300
            }
            PropertyAnimation {
                target: bsklrgradient1
                properties: "color"
                to: rectangle1.gradientcolor0
                duration: 300
            }
        }
        ParallelAnimation {
            id: bsklExitAnim
            PropertyAnimation {
                target: bsklrgradient0
                properties: "color"
                to: rectangle1.gradientcolor0
                duration: 300
            }
            PropertyAnimation {
                target: bsklrgradient1
                properties: "color"
                to: rectangle1.gradientcolor1
                duration: 300
            }
        }
        MouseArea
        {
            anchors.fill: parent
            id:  sklButtonMouseArea
            anchors.rightMargin: 0
            anchors.bottomMargin: -1
            anchors.leftMargin: 0
            anchors.topMargin: 1
            hoverEnabled: true
            onEntered: bsklEnterAnim.start()
            onExited: bsklExitAnim.start()
            //При нажатии вызвать функцию
            onClicked: _kompas.changeSkl()
        }
    }
    Rectangle
    {
        id: infoButton
        x: 657
        y: 113
        width: 135
        height: 43
        visible: true
        anchors.right: parent.right
        anchors.rightMargin: 8
        Text {
            id:  infoButtonText
            anchors.centerIn: parent;
            text: "Доп. информация"
            anchors.verticalCenterOffset: 1
            anchors.horizontalCenterOffset: 3
            font.pixelSize: 15
            color: "#FFFFFF"
        }
        gradient: Gradient { // добавление градиента
            GradientStop {
                id: infogradient0
                position: 0
                color: rectangle1.gradientcolor0
            }
            GradientStop {
                id: infogradient1
                position: 1
                color: rectangle1.gradientcolor1
            }
        }
        ParallelAnimation {
            id: infoEnterAnim
            PropertyAnimation {
                target: infogradient0
                properties: "color"
                to: rectangle1.gradientcolor1
                duration: 300
            }
            PropertyAnimation {
                target: infogradient1
                properties: "color"
                to: rectangle1.gradientcolor0
                duration: 300
            }
        }
        ParallelAnimation {
            id: infoExitAnim
            PropertyAnimation {
                target: infogradient0
                properties: "color"
                to: rectangle1.gradientcolor0
                duration: 300
            }
            PropertyAnimation {
                target: infogradient1
                properties: "color"
                to: rectangle1.gradientcolor1
                duration: 300
            }
        }
        MouseArea
        {
            anchors.fill: parent
            id:  pButtonMouseArea
            anchors.rightMargin: 0
            anchors.bottomMargin: -1
            anchors.leftMargin: 0
            anchors.topMargin: 1
            hoverEnabled: true
            onEntered: infoEnterAnim.start()
            onExited: infoExitAnim.start()
            onClicked: _kompas.changeInfoScreenVisibility()
        }
    }
}
