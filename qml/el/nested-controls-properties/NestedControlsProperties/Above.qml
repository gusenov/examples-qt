import QtQuick 2.0

Item {
    property alias sun: sun_
    property alias sky: sky_

    Sky {
        id: sky_
        anchors.fill: parent

        onSkyClicked: {
            console.log("onSkyClicked")
        }
    }

    Sun {
        id: sun_

        height: parent.height / 2
        width: height

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        onSunPressed: {
            color = "orange"
        }
    }

}
