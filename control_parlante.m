function varargout = control_parlante(varargin)
% CONTROL_PARLANTE MATLAB code for control_parlante.fig
%      CONTROL_PARLANTE, by itself, creates a new CONTROL_PARLANTE or raises the existing
%      singleton*.
%
%      H = CONTROL_PARLANTE returns the handle to a new CONTROL_PARLANTE or the handle to
%      the existing singleton*.
%
%      CONTROL_PARLANTE('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in CONTROL_PARLANTE.M with the given input arguments.
%
%      CONTROL_PARLANTE('Property','Value',...) creates a new CONTROL_PARLANTE or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before control_parlante_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to control_parlante_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help control_parlante

% Last Modified by GUIDE v2.5 22-Jan-2020 23:00:20

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @control_parlante_OpeningFcn, ...
                   'gui_OutputFcn',  @control_parlante_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before control_parlante is made visible.
function control_parlante_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to control_parlante (see VARARGIN)

global frecuencia Fs t iniciar
iniciar=0;
frecuencia=1;
Fs=3000;
t=0:1/Fs:1;
x=0.1*cos(2*pi*frecuencia*t);
axes(handles.axes1);
plot(t,x);
set(handles.slider1, 'Max',100);
set(handles.slider1, 'Min', 1);
set(handles.slider1, 'SliderStep' , [(1/99),0.1] );
set(handles.slider1,'Value',1);
set(handles.frec,'String',1);

% Choose default command line output for control_parlante
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes control_parlante wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = control_parlante_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on slider movement.
function slider1_Callback(hObject, eventdata, handles)
    global frecuencia t Fs iniciar x player
    frecuencia= get(handles.slider1,'Value');
    set(handles.frec,'String',frecuencia)
    x=0.5*cos(2*pi*frecuencia*t);
    axes(handles.axes1);
    plot(t,x);
    player = audioplayer(x, Fs);
    stop(player);
    get(player,'TimerPeriod')
    get(player,'TimerFcn')
    while(iniciar)
    play(player)    
    pause(0.001)
end
    
    
    
    


% --- Executes during object creation, after setting all properties.
function slider1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end



function frec_Callback(hObject, eventdata, handles)
% hObject    handle to frec (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of frec as text
%        str2double(get(hObject,'String')) returns contents of frec as a double


% --- Executes during object creation, after setting all properties.
function frec_CreateFcn(hObject, eventdata, handles)
% hObject    handle to frec (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in b_iniciar.
function b_iniciar_Callback(hObject, eventdata, handles)
global iniciar x Fs player
iniciar=1
%play(player);
%player.StopFcn = @(src, event) play(src);
n=0;
while(iniciar)
    play(player)    
    pause(0.001)
end

% --- Executes on button press in b_parar.
function b_parar_Callback(hObject, eventdata, handles)
global iniciar player
iniciar=0
stop(player);

