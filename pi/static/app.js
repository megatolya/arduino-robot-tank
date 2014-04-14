HTMLAnchorElement.prototype.active = function() {
    deactiveButtons();
    this.classList.add('_active');
}
HTMLAnchorElement.prototype.deactive = function() {
    deactiveButtons();
    this.classList.remove('_active');
}

var oldParam;
function getRequest(param) {
    var xhr = new XMLHttpRequest();
    if (oldParam !== param) {
        oldParam = param;
        xhr.open('GET', '/' + param, true);
        xhr.send();
    }
}

var nextDir = null;

setInterval(function() {
    getRequest(nextDir || 'stop');
    if (!nextDir)
        deactiveButtons();

}, 10);

function notify(dir) {
    nextDir = dir;
}

function getButtons() {
    return [upElem, downElem, leftElem, rightElem];
}

function deactiveButtons() {
    getButtons().forEach(function(elem) {
        elem.classList.remove('_active');
    });
}

function handleDirection(dir) {
    notify(dir);
    window[dir + 'Elem'].active();
}

function stop() {
    notify(null);
    deactiveButtons();
}

document.addEventListener('DOMContentLoaded', function() {
    ['up', 'down', 'left', 'right'].forEach(function(dir) {
        window[dir] = handleDirection.bind(this, dir);
        var elem = window[dir + 'Elem'] = document.querySelector('.' + dir);
        elem.direction = dir;
    });

    getButtons().forEach(function(button) {
        button.addEventListener('mousedown', function() {
            notify(button.direction);
            button.active();
        });
    });

    document.addEventListener('mouseup', function() {
        stop();
    });

    document.addEventListener('keydown', function(e) {
        switch (e.keyCode) {
            // up
            case 38:
                up();
                break;

            // down
            case 40:
                down();
                break;

            // left
            case 37:
                left();
                break;

            // right
            case 39:
                right();
                break;
        }
    });

    document.addEventListener('keyup', stop);
});
