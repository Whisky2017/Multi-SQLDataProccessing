package com.test.service2;

import com.test.pojo2.Fuheplan2;

import java.util.List;

/**
 * Created by 世康 on 2016/9/19.
 */
public interface FuheplanService {

    public List<Fuheplan2> getFuheplanAll();

    public List<Fuheplan2> getFuheplan(int currentPaging, int pageSize);

    public Fuheplan2 getFuheplanById(String id);

    public int getFuheplanCount();
}
